#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,d[100005],f[100005],ans=0;
void solve(){
    cin>>n;
    f[1]++;
    d[1]=1;
    rep(i,2,n+1){
        int x;
        cin>>x;
        d[i]=d[x]+1;
        f[d[i]]++;
    }
    rep(i,1,n+1){
        ans+=f[i]%2;
    }
    cout<<ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}