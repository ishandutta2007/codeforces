#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRec
{
public:
    SegmentTreeRec(int n) : n(n)
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
            update(x, y, addend, id<<1, l, m);
            update(x, y, addend, id<<1|1, m, r);
            data[id] = std::min(data[id<<1], data[id<<1|1]);
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
    std::vector<int> data, todo;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    SegmentTreeRec st(n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        st.update(i, i+1, value);
    }

    int m;
    cin >> m;
    string line;
    getline(cin, line);
    for (int i = 0; i < m; i++) {
        getline(cin, line);
        stringstream ss(line);
        int lf, rg, v;
        ss >> lf >> rg;
        if (ss >> v) {
            if (lf <= rg)
                st.update(lf, rg+1, v);
            else {
                st.update(lf, n, v);
                st.update(0, rg + 1, v);
            }
        } else {
            if (lf <= rg)
                cout << st.minimum(lf, rg+1) << '\n';
            else {
                cout << min(st.minimum(lf, n), st.minimum(0, rg+1)) << '\n';
            }
        }
    }
}