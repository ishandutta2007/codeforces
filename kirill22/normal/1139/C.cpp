#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> > g(100001);
bool used[int(1e5 + 10)];
long long co=0;
void dfs(int v){
    co++;
    used[v] = true;
    for (int i=0;i<g[v].size();i++){
        int x=g[v][i];
        if (!used[x]){
            dfs(x);
        }
    }

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        used[i]=false;
    }
    const long long MOD=1e9+7;

    for(int i=0;i<n-1;i++){
        int x,y,l;
        cin >> x >> y >> l;
        if (l==0){
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);


        }
    }
    long long ans=1;
    for(int i=0;i<k;i++){
        ans*=n;
        ans%=MOD;
    }
    for(int i=0;i<n;i++){
        if (!used[i]){
            co=0;
            dfs(i);
            long long ans1=1;
    for(int i=0;i<k;i++){
        ans1*=co;
        ans1%=MOD;
    }
    ans=(ans-ans1+3*MOD)%MOD;
        }
    }
    cout << ans;




    return 0;

}