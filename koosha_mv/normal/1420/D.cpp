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
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=6e5+99,mod=998244353;

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int n,k,c,tdd[N],l[N],r[N],b[N],mark[N];
map<int,int> T;
ll ans;

void do_it(){
    sort(b,b+n+n);
    f(i,0,2*n)
        if(i==0 || b[i]!=b[i-1])
            T[b[i]]=++c;
    f(i,0,n){
        l[i]=T[l[i]],r[i]=T[r[i]];
        tdd[l[i]]++;
        mark[l[i]]++;
        mark[r[i]+1]--;
    }
}

int main(){
    make_fac();
    cin>>n>>k;
    f(i,0,n){
        Gett(l[i],r[i]);
        b[i*2]=l[i];
        b[i*2+1]=r[i];
    }
    do_it();
    f(i,1,c+1){
        mark[i]+=mark[i-1];
        Add(ans ,1ll*C(k,mark[i])-C(k,mark[i]-tdd[i])+mod);
    }
    cout<<ans;
}