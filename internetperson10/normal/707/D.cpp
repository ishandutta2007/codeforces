#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bitset<1000> shelf[100001];

int anses[100001];
int op = 0, i, j, ans = 0, n, m;

struct Bookcase {
    int lx, rx, pos, val = 0;
    Bookcase *ls = nullptr, *rs = nullptr;
    Bookcase(int l, int r, int p = -1, int ov = 0, int v = 0, Bookcase *sl = nullptr, Bookcase *sr = nullptr) : lx(l), rx(r), pos((l+r)/2) {
        val = ov;
        if(pos == p) {
            anses[v] = anses[v-1];
            shelf[v] = shelf[val];
            anses[v] -= shelf[v].count();
            if(op == 1) {
                shelf[v].set(j-1, 1);
            }
            if(op == 2) {
                shelf[v].set(j-1, 0);
            }
            if(op == 3) {
                for(int z = 0; z < m; z++) {
                    shelf[v].flip(z);
                }
            }
            anses[v] += shelf[v].count();
        }
        val = v;
        if(sl != nullptr) ls = sl;
        else if(l < pos) ls = new Bookcase(l, pos);
        if(sr != nullptr) rs = sr;
        else if(pos+1 < r) rs = new Bookcase(pos+1, r);
    }
    Bookcase* set(int x, int v) {
        if(rx <= x || x+1 <= lx) return this;
        if(x < pos) return new Bookcase(lx, rx, x, val, val, ls->set(x, v), rs);
        if(x == pos) return new Bookcase(lx, rx, x, val, v, ls, rs);
        if(pos < x) return new Bookcase(lx, rx, x, val, val, ls, rs->set(x, v));
        assert(false);
    }
};

Bookcase* bookcases[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Wait will just blindly applying it work
    // Big if true
    int q;
    cin >> n >> m >> q;
    shelf[0].reset();
    bookcases[0] = new Bookcase(0, n);
    anses[0] = 0;
    for(int t = 1; t <= q; t++) {
        cin >> op;
        if(op == 1) {
            cin >> i >> j;
            bookcases[t] = bookcases[t-1]->set(i-1, t);
        }
        if(op == 2) {
            cin >> i >> j;
            bookcases[t] = bookcases[t-1]->set(i-1, t);
        }
        if(op == 3) {
            cin >> i;
            bookcases[t] = bookcases[t-1]->set(i-1, t);
        }
        if(op == 4) {
            int k;
            cin >> k;
            bookcases[t] = bookcases[k];
            anses[t] = anses[k];
        }
        cout << anses[t] << '\n';
    }
}