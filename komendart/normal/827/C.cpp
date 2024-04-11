#include <bits/stdc++.h>

using namespace std;

const int maxw = 32 * 1e5;
int memory[maxw];
int *memp = memory;

struct SegmentTree {
    int *tree;
    int tsize;

    SegmentTree() {}

    SegmentTree(int n) {
        for (tsize = 1; tsize <= n; tsize <<= 1);
        tree = memp;
        memp += 2 * tsize;
    }

    void build(const vector<int> &c) {
        for (int i = tsize; i < 2 * tsize; ++i) {
            tree[i] = 0;
        }
        for (auto i: c) {
            tree[tsize + i] = 1;
        }
        for (int i = tsize - 1; i >= 1; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void change(int pos, int value) {
        assert(0 <= pos);
        assert(pos < tsize);
        pos += tsize;
        tree[pos] = value;
        for (; pos > 1; pos >>= 1) {
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
        }
    }

    int get(int l, int r) {
        int ans = 0;
        for (l += tsize, r += tsize + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += tree[l++];
            if (r & 1) ans += tree[--r];
        }
        return ans;
    }
};

struct Query {
    int tp, first, second;
    string str;
};

int ord(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
    assert(0);
}

int n;
string s;
int q;
vector<Query> queries;
vector<int> ans;

void solve(int len) {
    memp = memory;
    vector< vector<SegmentTree> > tree(4, vector<SegmentTree>(len));
    vector< vector< vector<int> > > arr(4, vector< vector<int> >(len));
    for (int i = 0; i < n; ++i) {
        int ch = ord(s[i]);
        arr[ch][i % len].push_back(i / len);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < len; ++j) {
            /*if (!arr[i][j].empty() && len == 4) {
                cerr << i << ' ' << j << endl;
                for (auto k: arr[i][j]) cerr << ' ' << k; cerr << endl;
            }*/
            tree[i][j] = SegmentTree(n / len + 1);
            tree[i][j].build(arr[i][j]);
        }
    }

    for (int i = 0; i < q; ++i) {
        int tp = queries[i].tp;
        if (tp == 1) {
            int x = queries[i].first;
            int ch = ord(queries[i].str[0]);
            --x;
            for (int j = 0; j < 4; ++j) {
                tree[j][x % len].change(x / len, (j == ch) ? 1: 0);
            }
        } else {
            int l = queries[i].first, r = queries[i].second;
            const string &str = queries[i].str;
            --l; --r;
            if (str.size() != len) continue;
            int answer = 0;
            for (int j = 0; j < len; ++j) {
                int ch = ord(str[j]);
                int left = (l + j) / len;
                int right = r / len;
                if (r % len < (j + l) % len) --right;
                //cerr << ch << ' ' << (l + j) % len << ' ' << left << ' ' << right << endl;
                if (left <= right) {
                    answer += tree[ch][(l + j) % len].get(left, right);
                }
            }
            ans[i] = answer;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> s;
    n = s.size();
    cin >> q;
    queries.resize(q);
    ans.resize(q, -1);
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x; string str;
            cin >> x >> str;
            queries[i] = {tp, x, -1, str};
        } else {
            int l, r; string str;
            cin >> l >> r >> str;
            queries[i] = {tp, l, r, str};
        }
    }
    for (int len = 1; len <= 10; ++len) {
        solve(len);
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i] != -1) cout << ans[i] << '\n';
    }
}