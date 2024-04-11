    #include <bits/stdc++.h>
    using namespace std;
    #define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
    #define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
    #define Get(x,y) scanf("%I64d%I64d",&x,&y);
    #define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
    #define eror(x) cout<<#x<<'='<<(x)<<endl;
    #define f_(i,a,b) for(int i=a;i>=b;i--)
    #define Gett(x,y) scanf("%d%d",&x,&y);
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define get(x) scanf("%I64d",&x);
    #define gett(x) scanf("%d",&x);
    #define maxm(a,b) a=max(a,b);
    #define minm(a,b) a=min(a,b);
    #define lst(x) x[x.size()-1]
    #define sz(x) int(x.size())
    #define Add(x,y) x=(x+y)%mod;
    #define mp make_pair
    #define ll long long
    #define pb push_back
    #define S second
    #define F first
     
    const int N=1e6+99,mod=998244353;
     
    int n,m,d[N];
    ll a[N],sum1,sum2;
     
    ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
    int lb(int x){
        int l=0,r=n+1,mid;
        while(l+1<r){
            mid=(l+r)/2;
            if(d[mid]<x) l=mid;
            else r=mid;
        }
        sum2=a[l],sum1=a[n]-a[l];
        return l;
    }
     
    int main(){
        cin>>n>>m;
        f(i,1,n+1) cin>>d[i];
        sort(d+1,d+n+1);
        f(i,1,n+1) a[i]=a[i-1]+d[i];
        
        f(i,0,m){
            int x,y,u,v;
            Gett(x,y);
            v = lb(y);
            u = n-v;
            sum1 %=mod;
            sum2 %=mod;
            if(u<x){
                cout<<0<<'\n';
            }
            else{
                int mv=u-x;
                int ans = 1ll * mv * sum1 % mod * pow(u,mod-2,mod) % mod;
                Add(ans , 1ll * (mv+1) * pow(u+1,mod-2,mod) % mod * sum2 % mod);
                cout<<ans<<'\n';
            }
        }
    }