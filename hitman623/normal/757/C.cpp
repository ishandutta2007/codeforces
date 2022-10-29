#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
vi v[1000005];
map<vi,int> mp;
int f[1000006];
void solve()
{
    int n,m,ans=1;
    cin>>n>>m;
    f[0]=1;
    rep(i,1,m+1){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    rep(i,0,n){
        int g;
        cin>>g;
        while(g--){
            int x;
            cin>>x;
            v[x].pb(i);
        }
    }
    rep(i,1,m+1){
        sort(all(v[i]));
        mp[v[i]]++;
    }
    for(auto i:mp){
        ans=(1LL*ans*f[i.y])%hell;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}