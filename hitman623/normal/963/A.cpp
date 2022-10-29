#include <bits/stdc++.h>

#define int         unsigned long long
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
#define hell        1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a,b,k;
string s;
int expo(int base,int exponent,int mod){
    int ans=1;
    base%=hell;
    while(exponent!=0){
        if(exponent&1) ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    cin>>n>>a>>b>>k;
    cin>>s;
    int ans=0,cura=expo(a,n,hell),curb=1,inva=expo(a,hell-2,hell);
    rep(i,0,k){
        int w=(cura*curb)%hell;
        ans=(ans+((s[i]=='+')?1:hell-1)*w)%hell;
        cura=(cura*inva)%hell;
        curb=(curb*b)%hell;
    }
    int h=(n+1)/k;
    int r=expo((b*inva)%hell,k,hell);
    if(r==1){
        ans=(ans*h)%hell;
        cout<<ans<<endl;
        return;
    }
    int y=(expo(r,h,hell)-1+hell)%hell;
    ans=(ans*y)%hell;
    ans=(ans*expo((r-1+hell)%hell,hell-2,hell))%hell;
    cout<<((ans%hell)+hell)%hell<<endl;
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