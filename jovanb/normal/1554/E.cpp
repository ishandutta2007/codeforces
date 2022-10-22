#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;
const int N = 100000;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int x){ return pw(x, MOD - 2); }

vector <int> divs[N+5];

int soln[N+5];
vector <int> graf[N+5];

int k;

int dfs(int v, int p){
    int deg = 0;
    int uk = 1;
    for(auto c : graf[v]){
        if(c == p) continue;
        deg++;
        int x = dfs(c, v);
        if(x == -1) return -1;
        else if(x == 1) deg--;
    }
    if(deg%k == 0) return 0;
    if((deg+1)%k == 0) return 1;
    return -1;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        graf[i].clear();
        soln[i] = 0;
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(auto c : divs[n-1]){
        k = c;
        soln[c] = (dfs(1, 0) == 0);
    }
    soln[1] = pw(2, n-1);
    for(int i=n; i>=1; i--){
        for(int j=2*i; j<=n; j+=i){
            soln[i] -= soln[j];
        }
    }
    for(int i=1; i<=n; i++) cout << soln[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=2; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            divs[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}