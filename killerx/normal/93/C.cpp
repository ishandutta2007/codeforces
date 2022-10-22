#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int tar;
string C[30];

struct Op {
    int c, a, k, b;
    Op(int c, int a, int k, int b): c(c), a(a), k(k), b(b) {}
    friend ostream &operator << (ostream &o, Op x) {
        if (x.a == -1) {
            o << "lea " << C[x.c] << ", [";
            if (x.k != 1) o << x.k << "*";
            o << C[x.b] << "]";
        } else {
            o << "lea " << C[x.c] << ", [";
            o << C[x.a] << " + ";
            if (x.k != 1) o << x.k << "*";
            o << C[x.b] << "]";
        }
        return o;
    }
};

int ex[30];
vector <Op> ops;

void dfs(int dep, int lim) {
    if (dep == lim) {
        if (ex[dep - 1] == tar) {
            cout << ops.size() << endl;
            rep(i, ops.size()) {
                cout << ops[i] << endl;
            }
            exit(0);
        }
        return ;
    }
    for (int a = -1; a < dep; ++ a) {
        for (int k = 1; k <= 8; k <<= 1) {
            for (int b = 0; b < dep; ++ b) {
                ex[dep] = (a == -1 ? 0 : ex[a]) + k * ex[b];
                if (ex[dep] > tar) continue;
                ops.pb(Op(dep, a, k, b));
                dfs(dep + 1, lim);
                ops.pop_back();
            }
        }
    }
}

int main() {
    rep(i, 30) C[i] = string("e", 1) + char('a' + i) + "x";
    cin >> tar;
    ex[0] = 1;
    for (int lim = 1; ; ++ lim) dfs(1, lim);
    return 0;
}