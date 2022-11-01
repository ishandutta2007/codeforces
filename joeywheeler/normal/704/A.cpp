#include <bits/stdc++.h>

#define FO(i,a,b) for (int i=a;i<b;i++)
#define sz(v) int(v.size())

using namespace std;

int n, q;

set<int> ev[300005];
set<pair<int,int> > upev;

int main() {
    scanf("%d%d", &n, &q);
    int ni = 0;
    FO(i,0,q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x; scanf("%d", &x);
            ev[x].insert(ni);
            upev.emplace(ni,x);
            ni++;
        } else if (t == 2) {
            int x; scanf("%d", &x);
            for (int y : ev[x]) {
                upev.erase(make_pair(y,x));
            }
            ev[x].clear();
        } else if (t == 3) {
            int m; scanf("%d", &m);
            while (sz(upev) &&
                upev.begin()->first < m) {
                int y, x;
                tie(y,x) = *upev.begin();
                upev.erase(upev.begin());
                ev[x].erase(y);
            }
        }
        printf("%d\n", sz(upev));
    }
}