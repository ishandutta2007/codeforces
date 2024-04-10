#include <bits/stdc++.h>
#define int         long long
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
int ans[1002],f[2002],inv[2002];
int expo(int base,int exponent,int mod){                                //return base^exponent modulo modulus
    int ans=1;
    while(exponent!=0){
        if((exponent&1)==1){
            ans=(1LL*ans*base)%mod;
        }
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans;
}
int C(int n,int r){
    if(n<r) return 0;
    return (((f[n]*inv[r])%hell)*inv[n-r])%hell;
}
void solve()
{
    ans[0]=hell;
    f[0]=1;
    inv[0]=1;
    rep(i,1,2002){
        f[i]=(i*f[i-1])%hell;
        inv[i]=expo(f[i],hell-2,hell);
    }
    ans[1]=0;
    rep(i,2,1001){
        int d=i;
        int c=__builtin_popcount(i);
        ans[i]=ans[c]+1;
    }
    int k,n,cnt=0,finalans=0;
    string s;
    cin>>s>>k;
    n=sz(s);
    if(k==0) {cout<<1;return;}
    if(k==1) {cout<<n-1;return;}
    vi v;
    rep(i,0,sz(s)){
        if(s[i]=='0') continue;
        rep(j,cnt,1001){
            if(ans[j]==k-1){
                finalans=(finalans+C(n-i-1,j-cnt))%hell;
            }
        }
        cnt++;
    }
    if(ans[cnt]==k-1) finalans=(finalans+1)%hell;
    cout<<finalans<<endl;
}

signed main()
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