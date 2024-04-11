#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define pi pair<int,int>
 
const int N=1e6+9,mod=998244353;

int n,e,t,p,cnt,ans;
string s;

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int main(){
    make_fac();
    cin>>s;   
    n=s.size();
    f(i,0,n)
        e+=(s[i]!='('),t+=(s[i]=='?');
    f(i,0,n){
        e--;
        p+=(s[i]=='?');
        cnt+=(s[i]=='(');
        if(0<=e && e<=t){
            Add(ans,1ll*C(e,t)*cnt%mod);
            Add(ans,1ll*C(e,t)*e%mod*p%mod*pow(t,mod-2,mod)%mod);
        }
    }
    cout<<ans;
}