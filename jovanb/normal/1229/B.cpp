#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll res;
const int MOD = 1000000007;

int add(ll a, ll b){
    return (a+b)%MOD;
}

int mul(ll a, ll b){
    return (a*b)%MOD;
}

int depth[100005];
vector <int> graf[100005];
ll val[100005];
map <ll, int> br[100005];

void dfs(int v, int parent){
    for(auto c : br[parent]){
        ll a = c.first;
        ll b = c.second;
        a = __gcd(a, val[v]);
        br[v][a] += b;
    }
    br[v][val[v]]++;
    for(auto c : br[v]){
        res = add(res, mul(c.first, c.second));
    }
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    cout << res;
    return 0;
}