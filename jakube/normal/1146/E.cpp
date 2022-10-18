#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy() {
        n = 200'001;
        data.resize(4 * n);
        todo.assign(4 * n, 0);
        build();
    }

    void build(int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l == r - 1) {
            data[id] = {l - 100'000, l - 100'000};
        } else {
            int m = (l + r) >> 1;
            build(id << 1, l, m);
            build(id << 1 | 1, m, r);
            data[id] = combine(data[id << 1], data[id << 1 | 1]);
        }
    }

    pair<int, int> combine(pair<int, int> const& a, pair<int, int> const& b) {
        return {min(a.first, b.first), max(a.second, b.second)};
    }

    void query(vector<int>& res, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (l + 1 == r) {
            res[l] = data[id].first;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            query(res, id << 1, l, m);
            query(res, id << 1 | 1, m, r);
        }
    }

    void greater(int value, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (data[id].first > value) {
            data[id] = invert(data[id]);
            todo[id] ^= 1;
        } else if (data[id].second > value) {
            push(id, l, r);
            int m = (l + r) >> 1;
            greater(value, id << 1, l, m);
            greater(value, id << 1 | 1, m, r);
            data[id] = combine(data[id << 1], data[id << 1 | 1]);
        }
    }

    void smaller(int value, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (data[id].second < value) {
            data[id] = invert(data[id]);
            todo[id] ^= 1;
        } else if (data[id].first < value) {
            push(id, l, r);
            int m = (l + r) >> 1;
            smaller(value, id << 1, l, m);
            smaller(value, id << 1 | 1, m, r);
            data[id] = combine(data[id << 1], data[id << 1 | 1]);
        }
    }

    pair<int, int> invert(pair<int, int> p) {
        return {-p.second, -p.first};
    }

private:
    void push(int id, int l, int r)
    {
        if (todo[id]) {
            data[id << 1] = invert(data[id << 1]);
            todo[id << 1] ^= 1;
            data[id << 1 | 1] = invert(data[id << 1 | 1]);
            todo[id << 1 | 1] ^= 1;
            todo[id] = 0;
        }
    }

    int n;
    std::vector<pair<int, int>> data;
    std::vector<int> todo;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    SegmentTreeRecLazy st;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '>')
            st.greater(x);
        else
            st.smaller(x);
    }
    vector<int> res(200'001);
    st.query(res);

    for (int x : a) {
        cout << res[x + 100'000] << ' ';
    }
    cout << endl;
}