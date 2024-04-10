#include <bits/stdc++.h>
using namespace std;

int convert(char c) {
        int val = 0;
        if ('0' <= c && c <= '9') {
            val = c - '0';
        }
        if ('a' <= c && c <= 'z') {
            val = c - 'a' + 10;
        }
        if ('A' <= c && c <= 'Z') {
            val = c - 'A' + 36;
        }
        return val;
}


class SegmentTreeRec
{
public:
    SegmentTreeRec(int n) : n(n) { data.assign(4 * n, 0); }

    int get_pos(int pos, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (l + 1 == r)
            return l;

        int m = (l + r) >> 1;
        if (pos > data[id << 1]) {
            return get_pos(pos - data[id << 1], id << 1 | 1, m, r);
        } else {
            return get_pos(pos, id << 1, l, m);
        }
    }

    void update(int pos, int value, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (pos < l || pos >= r) {
        } else if (l == pos && pos + 1 == r) {
            data[id] = value;
        } else {
            int m = (l + r) >> 1;
            update(pos, value, id << 1, l, m);
            update(pos, value, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    SegmentTreeRec st(n);
    for (int i = 0; i < n; i++) {
        st.update(i, 1);
    }

    vector<set<int>> sets(62);
    for (int i = 0; i < n; i++) {
        sets[convert(s[i])].insert(i);
    }
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        char c;
        cin >> c;
        int l_pos = st.get_pos(l);
        int r_pos = st.get_pos(r);
        auto& set = sets[convert(c)];
        auto l_it = set.lower_bound(l_pos);
        auto r_it = set.upper_bound(r_pos);
        for (auto it = l_it; it != r_it; ++it)
            st.update(*it, 0);
        set.erase(l_it, r_it);
    }

    for (int i = 0; i < n; i++) {
        if (sets[convert(s[i])].count(i))
            cout << s[i];
    }
    cout << endl;
}