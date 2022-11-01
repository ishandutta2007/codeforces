#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
pair<int,int> cn[30000005];
int x[100005], y[100005];
int xs[100005], nx;
tuple<int,int,int> op[200005];
long long ans[100005];
map<int,int> xtc;

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,n) {
        scanf("%d %d", x+i, y+i);
        xs[i] = x[i];
        op[2*i] = make_tuple(y[i]-k+1, x[i], 1);
        op[2*i+1] = make_tuple(y[i]+1, x[i], -1);
    }
    sort(xs,xs+n);
    int lx = -2e9;
    FO(i,0,n) {
        while (lx <= xs[i]) {
            lx = max(lx, xs[i]-k+1);
            lx++; nx++;
        }
        xtc[xs[i]] = nx-1;
    }
    FO(i,0,nx) cn[i] = make_pair(0, -2e9);
    sort(op,op+2*n);
    FO(i,0,2*n) {
        int qy, qx, dt;
        tie(qy,qx,dt) = op[i];
        int j = xtc[qx]-k+1;
        FO(p,j,j+k) {
            ans[cn[p].first] += 0ll + qy - cn[p].second;
            cn[p].first += dt;
            cn[p].second = qy;
        }
    }
    FO(i,1,n+1) printf("%lld%c", ans[i], " \n"[i==n]);
}