#include <bits/stdc++.h>

using namespace std;
namespace kn {
    int n, k;
    vector<vector<int> > g;
    vector<int> mt;
    vector<char> used;

    void ini() {
        g.resize(n);
    }

    bool try_kuhn(int v) {
        if (used[v]) return false;
        used[v] = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (mt[to] == -1 || try_kuhn(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }

    void kn(const vector<int> &por) {
        mt.assign(k, -1);
        for (int v : por) {
            used.assign(n, false);
            try_kuhn(v);
        }
    }

//    int main() {
//        ...   ...
//
//
//        for (int i=0; i<k; ++i)
//            if (mt[i] != -1)
//                printf ("%d %d\n", mt[i]+1, i+1);
//    }

}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);

    int d, n;
    cin >> d >> n;

    vector<string> msk(n);
    vector<int> x(n);
    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        cin >> msk[i];
        x[i] = 0;
        for (int j = 0; j < d; j++) {
            x[i] *= 2;
            x[i] += msk[i][j] - '0';
        }
        w[i] = __builtin_popcount(x[i]);
    }

    vector<int> por(n);
    iota(por.begin(), por.end(), 0);
    sort(por.begin(), por.end(), [&](int i, int j) {
        return w[i] > w[j];
    });

    kn::n = n;
    kn::k = n;
    kn::ini();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] < x[j]) {
                if ((x[i] & x[j]) == x[i]) {
                    kn::g[i].push_back(j);
                }
            }
        }
    }

    kn::kn(por);

    vector<int> is_first(n, 1);
    vector<int> nxt(n, -1);

    for (int i = 0; i < n; i++) {
        if (kn::mt[i] != -1) {
            nxt[kn::mt[i]] = i;
            is_first[i] = 0;
        }
    }

    vector<int> moves_res;
    for (int i = 0; i < n; i++) {
        if (is_first[i]) {
            int val = 0;
            int pos = i;
            while (pos != -1) {
                int to = x[pos];
                for (int j = 0; j < d; j++) {
                    if ((to & (1 << j)) && (!(val & (1 << j)))) {
                        moves_res.push_back(d - j - 1);
                    }
                }
                pos = nxt[pos];
                val = to;
            }
            moves_res.push_back(-1);
        }
    }
    moves_res.pop_back();

    cout << moves_res.size() << "\n";
    for (auto x : moves_res) {
        if (x == -1) {
            cout << "R" << ' ';
        } else {
            cout << x << ' ';
        }
    }
    return 0;
}