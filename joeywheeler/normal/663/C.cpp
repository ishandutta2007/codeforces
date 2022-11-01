#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<pair<int,int> > u[100005];
int targ;

int typ[100005];
vector<int> comp;
bool fal;

void go(int i, int tp) {
    if (typ[i] != -1) {
        if (tp != typ[i]) {
            fal = true;
        }
        return;
    }
    typ[i] = tp;
    comp.emplace_back(i);
    for (auto e : u[i]) {
        int otp = targ ^ e.second ^ tp;
        go(e.first,otp);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    FO(z,0,m) {
        int x, y; scanf("%d%d", &x, &y);
        char c; scanf(" %c", &c);
        int t = c == 'B' ? 0 : 1;
        u[x].emplace_back(y,t);
        u[y].emplace_back(x,t);
    }
    vector<int> bst;
    int hbst = -1;
    for (targ = 0; targ <= 1; targ++) {
        fal = false;
        FO(i,1,n+1) typ[i] = -1;
        vector<int> v;
        FO(i,1,n+1) if (typ[i] == -1) {
            comp.clear();
            go(i,0);
            if (fal) break;

            int n0 = 0, n1 = 0;
            for (int x : comp) if (typ[x] == 0) {
                n0++;
            } else {
                n1++;
            }
            if (n0 < n1) {
                for (int x : comp) if (typ[x] == 0) v.push_back(x);
            } else {
                for (int x : comp) if (typ[x] == 1) v.push_back(x);
            }
        }

        if (!fal) {
            if (hbst == -1 || sz(v) < sz(bst)) bst = v, hbst = 1;
        }
    }
    if (hbst == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", sz(bst));
        for (int x : bst) printf("%d ", x);
        printf("\n");
    }
}