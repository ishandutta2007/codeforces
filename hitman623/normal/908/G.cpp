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

// pos-1 digits >= d
// n-pos digits <= d

string s;
int n,dp[702][702][10][2][2][2];
int sol(int in,int cnt,int d,int fac,int got_it,int is_small){
    cnt=max(0,cnt);
    if(in==n) return cnt==0 and got_it;
    int &ans=dp[in][cnt][d][fac][got_it][is_small];
    if(ans!=-1) return ans;
    ans=0;
    if(is_small){
        rep(i,0,10){
            if(i>=d) ans=(ans+sol(in+1,cnt-1,d,fac,got_it|(i==d-fac),1))%hell;
            else ans=(ans+sol(in+1,cnt,d,fac,got_it|(i==d-fac),1))%hell;
        }        
    }
    else{
        int g=s[in]-'0';
        rep(i,0,g+1){
            if(i>=d) ans=(ans+sol(in+1,cnt-1,d,fac,got_it|(i==d-fac),i!=g))%hell;
            else ans=(ans+sol(in+1,cnt,d,fac,got_it|(i==d-fac),i!=g))%hell;            
        }
    }
    return ans;
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    cin>>s;
    n=sz(s);
    memset(dp,-1,sizeof dp);
    int ans=0;
    rep(d,1,10){
        rep(pos,1,n+1){
            int numbers=(sol(0,pos,d,0,0,0)-sol(0,pos,d+1,1,0,0)+hell)%hell;
            ans=(ans+1LL*d*expo(10,pos-1,hell)%hell*numbers%hell)%hell;
        }
    }
    cout<<ans<<endl;
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