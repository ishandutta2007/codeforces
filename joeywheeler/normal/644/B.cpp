#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
queue<tuple<int,int> > td;
ll cf = 0;
int n, b;
ll r[200005];

int main() {
    scanf("%d%d", &n, &b);
    FO(i,0,n) {
        int t, d; scanf("%d %d", &t, &d);
        while (cf <= t && sz(td)) {
            int D, I;
            tie(D,I) = td.front(); td.pop();
            cf = cf+D;
            r[I] = cf;
        }
        if (sz(td) == 0) {
            cf = max(cf,(ll)t);
        }
        if (sz(td) == b) {
            r[i] = -1;
        } else td.emplace(d, i);
    }
    while (sz(td)) {
        int D, I;
        tie(D,I) = td.front(); td.pop();
        cf = cf+D;
        r[I] = cf;
    }
    FO(i,0,n) printf("%lld%c", r[i], " \n"[i+1==n]);
}