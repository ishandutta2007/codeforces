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
int n,m,f[3000006];
ll ans[3000006],base;
void solve(){
    scanf("%d",&n);
    rep(i,1,n+1){
        int x;
        scanf("%d",&x);
        f[x]++;
    }
    rep(i,1,2000){
        for(int j=i*i;j<=3000000;j+=i){
            if(i==j/i) ans[j]+=1LL*f[i]*(f[i]-1);
            else ans[j]+=2LL*f[i]*f[j/i];
        }
    }
    for(int i=3000000;i>=1;i--){
        ans[i]+=ans[i+1];
        f[i]+=f[i+1];
    }
    rep(i,1,3000001){
        int y=(3000001+i-1)/i;
        if(i>=y) base+=1LL*(f[i]-f[i+1])*(f[y]-1);
        else base+=1LL*(f[i]-f[i+1])*f[y];
    }
    cin>>m;
    rep(i,0,m){
        int x;
        scanf("%d",&x);
        printf("%lld\n",base+ans[x]);
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}