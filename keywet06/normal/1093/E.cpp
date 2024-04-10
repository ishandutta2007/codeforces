#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename _Tp>
struct vic {
    int S;
    vector<_Tp> v;

    vic<_Tp>() {}
    vic<_Tp>(int _S) {
        S = _S;
        v.resize(S + 1);
    }

    void update(int i, _Tp k) {
        for (++i; i <= S; i += i & -i) v[i] = v[i] + k;
    }

    _Tp read(int i) {
        _Tp sum = 0;
        for (++i; i; i -= i & -i) sum = sum + v[i];
        return sum;
    }

    _Tp read(int l, int r) { return read(r) - read(l - 1); }

    int lower_bound(_Tp sum) {
        _Tp res = 0;
        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            if ((inx + (1 << i) <= S) && res + v[inx + (1 << i)] < sum) {
                inx += 1 << i;
                res += v[inx];
            }
        }
        return inx;
    }
};

struct seg_tree {
    int S;
    vvi pos;
    vector<vic<int>> value;

    seg_tree(int S) : S(S) {
        value.resize(2 * S);
        pos.resize(2 * S);
    }

    void prep(int i, int v) {
        for (i += S; i > 0; i /= 2) pos[i].push_back(v);
    }

    void init() {
        for (int i = 1; i < 2 * S; ++i) {
            sort(pos[i].begin(), pos[i].end());
            pos[i].erase(unique(pos[i].begin(), pos[i].end()), pos[i].end());
            value[i] = vic<int>(pos[i].size());
        }
    }

    void upd(int i, int v, int d) {
        for (i += S; i > 0; i /= 2) {
            int j =
                lower_bound(pos[i].begin(), pos[i].end(), v) - pos[i].begin();
            value[i].update(j, d);
        }
    }

    int read_ct(int i, int a, int b) {
        int y =
            (upper_bound(pos[i].begin(), pos[i].end(), b) - pos[i].begin()) - 1;
        int x = lower_bound(pos[i].begin(), pos[i].end(), a) - pos[i].begin();
        return (y >= x) ? value[i].read(x, y) : 0;
    }

    int query(int i, int j, int a, int b) {
        int res = 0;
        for (i += S, j += S; i <= j; i /= 2, j /= 2) {
            if ((i & 1) == 1) res = res + read_ct(i++, a, b);
            if ((j & 1) == 0) res = res + read_ct(j--, a, b);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vi a(N), ai(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        ai[--a[i]] = i;
    }

    vi b(N);
    seg_tree st(N);
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        b[i] = ai[b[i] - 1];
        st.prep(i, b[i]);
    }

    vi c = b;
    vector<array<int, 5>> ops(M);
    for (int i = 0; i < M; ++i) {
        cin >> ops[i][0];
        if (ops[i][0] == 1) {
            for (int j = 1; j < 5; ++j) {
                cin >> ops[i][j];
                ops[i][j]--;
            }
        } else {
            int& x = ops[i][1];
            int& y = ops[i][2];
            cin >> x >> y;
            swap(c[--x], c[--y]);
            st.prep(x, c[x]);
            st.prep(y, c[y]);
        }
    }

    st.init();
    for (int i = 0; i < N; ++i) {
        st.upd(i, b[i], 1);
    }

    for (int i = 0; i < M; ++i) {
        if (ops[i][0] == 1) {
            cout << st.query(ops[i][3], ops[i][4], ops[i][1], ops[i][2])
                 << "\n";
        } else {
            int& x = ops[i][1];
            int& y = ops[i][2];
            st.upd(x, b[x], -1);
            st.upd(y, b[y], -1);
            swap(b[x], b[y]);
            st.upd(x, b[x], 1);
            st.upd(y, b[y], 1);
        }
    }

    return 0;
}