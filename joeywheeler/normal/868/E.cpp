#include <bits/stdc++.h>
// TODO: CACHE!!!

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int w[55][55];
int deg[55];
int n;

ll dp[55][55][55][55];

ll f(int i, int j, int k, int l) {
    // we're at j, came from i, we have k behind us and want to know
    // worst case if l distributed ahead of us

    //printf("%d -> %d: beh: %d, ahe: %d\n", i, j, k, l);

    if (deg[j] == 1) l = 0;

    ll &res = dp[i][j][k][l];
    if (res != -1) return res;
    if (k+l == 0) res = 0;
    else if (deg[j] == 1) {
        //printf("WTF???\n");
        // turn back
        res = f(j, i, 0, k) + w[j][i];
    } else {
        assert(l);

        bool initcdp = false;
        vector<ll> cdp(l+1);
        vector<ll> ndp(l+1);
        vector<ll> u(l+1);
        fo(m,0,n) if (m != i && w[j][m]) {
            u[0] = 1e16;
            fo(t,1,l+1) {
                // if t hide along this edge and we chase them, how long will it take
                u[t] = f(j, m, k+l-t, t) + w[j][m];
            }
            if (initcdp) {
                fo(t,0,l+1) {
                    ndp[t] = 0;
                    fo(p,0,t+1) {
                        ndp[t] = max(ndp[t], min(u[p], cdp[t-p]));
                    }
                }
                cdp = ndp;
            } else {
                initcdp = true;
                cdp = u;
            }
        }
        
        res = cdp[l];
    }

    //printf("%d -> %d: beh: %d, ahe: %d | res = %lld\n", i, j, k, l, res);
    return res;
}

int s, m;
int ncr[55];

int dfs(int i, int p) {
    int ans = ncr[i];
    fo(j,0,n) if (j != p && w[i][j]) {
        ans += dfs(j, i);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    fo(i,0,n-1) {
        int u,v,c; scanf("%d %d %d", &u, &v, &c); u--; v--;
        w[u][v] = c;
        w[v][u] = c;
        deg[u]++; deg[v]++;
    }
    scanf("%d %d", &s, &m); s--;
    fo(i,0,m) {
        int loc;
        scanf("%d", &loc); loc--;
        ncr[loc]++;
    }
    ll ans = 1e16;
    fo(j,0,n) if (j != s && w[s][j]) {
        int cnt = dfs(j, s);
        if (cnt) {
            //printf("! %d -> %d: beh: %d, ahe: %d\n", s, j, m-cnt, cnt);
            ans = min(ans, f(s, j, m-cnt, cnt) + w[s][j]);
        }
    }
    printf("%lld\n", ans);
}