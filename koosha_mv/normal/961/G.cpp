    #include <bits/stdc++.h>
    using namespace std;
    #define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
    #define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
    #define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
    #define eror(x) cout<<#x<<'='<<(x)<<endl;
    #define f_(i,a,b) for(int i=a;i>=b;i--)
    #define Gett(x,y) scanf("%d%d",&x,&y);
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define get(x) scanf("%I64d",&x);
    #define All(x) x.begin(),x.end()
    #define gett(x) scanf("%d",&x);
    #define Add(x,y) x=(x+y)%mod
    #define maxm(a,b) a=max(a,b)
    #define minm(a,b) a=min(a,b)
    #define lst(x) x[x.size()-1]
    #define sz(x) int(x.size())
    #define mp make_pair
    #define ll long long
    #define pb push_back
    #define S second
    #define F first
     
    const int N=2e5+9,mod=1e9+7;
     
    int n,k,x,sum,res;
     
    int fac[N],ifac[N];
    ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
    void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
    int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}
     
    int calc(int x,int k){
        int res=0;
        f(i,0,k+1){
            int p=1ll*C(k-i,k)*pow(k-i,x,mod)%mod;
            if(i&1){ 
                Add(res,mod-p);
            }
            else Add(res,p);
        }
        res=1ll*res*pow(fac[k],mod-2,mod)%mod;
        return res;
    }
    int solve(int x,int k){
        int res=0;
        f(i,0,k+1){
            int p=1ll*C(k-i,k)*pow(k-i+1,x,mod)%mod;
            if(i&1){
                Add(res,mod-p); 
            }
            else Add(res,p);
        }
        res=1ll*res*pow(fac[k],mod-2,mod)%mod;
        return res;
    }
     
    int main(){
        make_fac();
        if(n==1){
            if(k==1) cout<<1;
            else cout<<0;
            return 0;
        }
        cin>>n>>k;
        f(i,0,n){
            gett(x);
            Add(sum,x);
        }
        Add(res,calc(n,k));
        Add(res,1ll*solve(n-2,k-1)*(n-1)%mod);
        cout<<1ll*sum*res%mod;
    }