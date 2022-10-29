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

int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int n,a[5005],ans[10005],pre[5005],inv[5005];
int up[5005][10005];
int get_down(int l,int r){
    if(l<=0 or r<0) return 0;
    if(r==0) return 1;
    r=l+r-1;
    if(r>=n) return 0;
    return 1LL*pre[r]*inv[l-1]%hell;
}
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    a[0]=pre[0]=inv[0]=1;
    rep(i,1,n+1) pre[i]=1LL*a[i]*pre[i-1]%hell,inv[i]=expo(pre[i],hell-2,hell);
    rep(i,1,n+1){
        rep(j,1,2*n-1){
            if(i>=2) up[i][j]=(0LL+up[i-1][j-1]+get_down(i-1,j-1)-get_down(i,j-2)+hell)%hell;
            ans[j]=(ans[j]+1LL*pre[i-1]*(up[i][j]+get_down(i,j)))%hell;
        }
    }
    rep(i,1,2*n-1) cout<<1LL*ans[i]*(hell+1)/2%hell<<" ";
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