#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, m;
int pos[300500];
int inv[300500];
vector<int> to[300050];
bool ok[300050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> pos[i];
        inv[pos[i]] = i;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    int ans = 0;
    for(int a = n-1; a >= 1; a--) {
        int i = pos[a];
        int now = 0;
        for(int j = 0; j < to[i].size(); j++) {
            int TO = to[i][j];
            if(ok[TO]) continue;
            //cout << TO << " " << inv[TO] << endl;
            if(inv[TO] > a) now++;
        }
        if(now + a == (n - ans)) {
            ans++;
            ok[i] = true;
        }
        //cerr << a << " "<< i << " " << now << endl;
    }
    cout << ans << endl;
    return 0;
}