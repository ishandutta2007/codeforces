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
#define MAXN 1000006
int p[1000006],fac[1000108],inv[1000108];
int expo(int base,int exponent){                                //return base^exponent modulo modulus
    int ans=1;
    while(exponent!=0) {
        if((exponent&1)==1){
            ans=(1LL*ans*base)%hell;
        }
        base=(1LL*base*base)%hell;
        exponent>>=1;
    }
    return ans;
}
void sieve()
{
    p[1]=1;
    for(int i=2;i<MAXN;i++)
        p[i]=i;
    for(int i=4;i<MAXN;i+=2)
        p[i]=2;
    for(int i=3;i*i<MAXN;i++){
        if(p[i]==i){
            for(int j=i*i;j<MAXN;j+=i)
                if(p[j]==j)
                    p[j]=i;
        }
    }
}
void solve()
{
    sieve();
    fac[0]=inv[0]=1;
    rep(i,1,1000108){
        fac[i]=(1LL*i*fac[i-1])%hell;
    }
    inv[1000107]=expo(fac[1000107],hell-2);
    for(int i=1000106;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
    int q;
    cin>>q;
    while(q--){
        int r,n,ans=1;
        mi f;
        cin>>r>>n;
        while(p[n]!=1){
            f[p[n]]++;
            n=n/p[n];
        }
        if(r<2){
            if(r==0) ans=1LL<<(f.size());
            else{
                for(auto i:f){
                    ans=(ans*(1+2*i.y))%hell;
                }
            }
        }
        else{
            r-=2;
            for(auto i:f){
                int n=i.y+1;
                ans=(1LL*ans*(2*n+r))%hell;
                ans=(1LL*ans*fac[n+r])%hell;
                ans=(1LL*ans*inv[r+2])%hell;
                ans=(1LL*ans*inv[n-1])%hell;
            }
        }
        cout<<ans<<endl;
    }
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