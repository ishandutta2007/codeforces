#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
    }

    int minimum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return std::numeric_limits<int>::max();
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return std::min(minimum(x, y, id << 1, l, m),
                            minimum(x, y, id << 1 | 1, m, r));
        }
    }

    void update(int x, int y, int addend, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] += addend;
            todo[id] += addend;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, addend, id << 1, l, m);
            update(x, y, addend, id << 1 | 1, m, r);
            data[id] = std::min(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    void push(int id, int l, int r)
    {
        data[id << 1] += todo[id];
        todo[id << 1] += todo[id];
        data[id << 1 | 1] += todo[id];
        todo[id << 1 | 1] += todo[id];
        todo[id] = 0;
    }

    int n;
    std::vector<long long> data, todo;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(n-1);
    vector<int> B(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    vector<vector<pair<int, int>>> diag(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        diag[a - 1].push_back({b - 1, c});
    }

    SegmentTreeRecLazy st(n-1);
    for (int i = 0; i < n-1; i++) {
        st.update(i, i+1, B[i]);
    }
    vector<long long> possible(n, 0);
    for (int i = 0; i < n; i++) {
        auto& ds = diag[i];
        for (auto p : ds) {
            if (p.first == n-1) {
                possible[i] += p.second;
            } else {
                int mi = min(p.second, st.minimum(p.first, n-1));
                possible[i] += mi;
                st.update(p.first, n-1, -mi);
            }
        }

//         for (int i = 0; i < n-1; i++) {
//             cout << st.minimum(i, i+1) << ' ';
//         }
//         cout << "|";
//         for (auto x : possible)
//             cout << " " << x;
//         cout << endl;
    }

    map<long long, int> s;
    vector<long long> psum(n, 0);
    psum[0] = possible[0];
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i-1] + possible[i];
    }
    A.push_back(0);
    for (int i = 0; i < n; i++) {
        s[A[i] + psum[i]]++;
    }
    cout << s.begin()->first << '\n';

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        // remove old value
        long long old = A[a] + psum[a];
        s[old]--;
        if (s[old] == 0)
            s.erase(old);
        // add new value
        A[a] = b;
        s[A[a] + psum[a]]++;
        // print
        cout << s.begin()->first << '\n';
    }
}