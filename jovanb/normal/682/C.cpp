#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, ll>> graf[100005];
ll tol[100005];

const ll INF = 1'000'000'000'000'000;

int cnt=0;

void dfs(int v, ll maxdis){
    if(tol[v] < maxdis) return;
    for(auto c : graf[v]){
        int a = c.first;
        ll b = c.second;
        dfs(a, max(b, maxdis+b));
    }
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> tol[i];
    for(int i=2; i<=n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back({i, b});
    }
    dfs(1, 0);
    cout << n-cnt;
    return 0;
}