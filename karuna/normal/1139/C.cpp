#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7;

vector<vector<int>> edges;
bool chk[202020];
ll fastpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b%2) {
            ret = (ret*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    return ret;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    edges.resize(n+1);

    int u, v, x;
    for (int i=0; i<n-1; i++) {
        scanf("%d %d %d", &u, &v, &x);
        if (x==0) {
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    }

    queue<int> q;
    vector<int> grp;
    int tmp;
    for (int i=1; i<=n; i++) {
        if (chk[i] == false) {
            int cnt = 0;
            q.push(i);
            while (!q.empty()) {
                tmp = q.front();
                q.pop();

                if (chk[tmp] == true)
                    continue;

                chk[tmp] = true;
                cnt++;

                for (int j=0; j<edges[tmp].size(); j++) {
                    q.push(edges[tmp][j]);
                }
            }
            grp.push_back(cnt);
        }
    }

    ll ans = fastpow(n, k);
    for (int i=0; i<grp.size(); i++) {
        ans = (ans+mod-fastpow(grp[i], k))%mod;
    }

    printf("%lld", ans);
}