#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int mod=998244353;
const int M=4e6+9;
int rev[M];
int n;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
void dft(vector<int>&A,int o){
    int lim=A.size(),inv3=kpow(3,mod-2);
    for(int i=0;i<lim;++i)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for(int k=1;k<lim;k<<=1){
        int wn=kpow((o?3:inv3),(mod-1)/(k<<1));
        for(int i=0;i<lim;i+=k<<1){
            for(int j=0,w=1;j<k;++j,w=1ll*w*wn%mod){
                int x=A[i+j],y=1ll*w*A[i+j+k]%mod;
                A[i+j]=(x+y)%mod;
                A[i+j+k]=(x-y+mod)%mod;
            }
        }
    }
}
void mul(vector<int>&a,vector<int>&b){
    int len=a.size()+b.size()-1,l=__lg(len-1)+1;
    len=1<<l;
    for(int i=0;i<len;++i)rev[i]=(rev[i>>1]>>1)|(i&1)<<(l-1);
    a.resize(len);
    b.resize(len);
    dft(a,1);
    dft(b,1);
    for(int i=0;i<len;++i)a[i]=1ll*a[i]*b[i]%mod;
    dft(a,0);
    int rex=kpow(len,mod-2);
    for(int i=0;i<len;++i)a[i]=1ll*a[i]*rex%mod;
}
vector<int>a[M];
void solve(int l,int r){
    if(l==r)return;
    int mid=l+r>>1;
    solve(l,mid);
    solve(mid+1,r);
    mul(a[l],a[mid+1]);
}
int d[M],fac[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        d[u]++;
        d[v]++;
    }
    for(int i=2;i<=n;++i)d[i]--;
    for(int i=1;i<=n;++i){
        if(d[i])a[i]={1,d[i]};
        else a[i]={1};
    }
    solve(1,n);
    fac[0]=1;
    int ans=0;
    for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
    for(int i=0;i<a[1].size();++i){
        if(n>=i)ans=(1ll*ans+mod+a[1][i]*((i&1)?-1ll:1ll)*fac[n-i])%mod;
    }
    printf("%d\n",ans);
    return 0;
}