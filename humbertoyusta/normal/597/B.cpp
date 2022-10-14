#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define maxn 2000002
using namespace std;

map<int,int> m;
int n,dp[maxn];
ii a[maxn];
set<int> v;
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i].f >> a[i].s;
        v.insert(a[i].f);
        v.insert(a[i].s);
    }

    int cont = 1;
    for( auto i : v )
        m[i]=cont++;

    for(int i=1; i<=n; i++){
        a[i].f = m[a[i].f];
        a[i].s = m[a[i].s];
        g[a[i].s].push_back(a[i].f);
    }

    for(int i=1; i<=2*n; i++){
        for(auto j : g[i]){
            dp[i]=max(dp[i],dp[j-1]+1);
        }
        dp[i]=max(dp[i],dp[i-1]);
    }

    cout << dp[2*n];

    return 0;
}