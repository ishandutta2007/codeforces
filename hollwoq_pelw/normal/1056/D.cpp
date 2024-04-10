#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e+7;
const int N = 100005;

vector<int> child[N];
vector<int> path;
int ans[N];

void dfs(int node){
    if (child[node].empty()){
        ans[node] = 1;
        return ;
    }
    for (auto next: child[node]){
        dfs(next);
        ans[node] += ans[next];
    }
}


void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        int x; cin >> x;
        child[x].pb(i);
    }
    dfs(1);
    sort(ans+1, ans+n+1);
    for (int i = 0; i < n; i++) cout << ans[i+1] << ' ';
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}