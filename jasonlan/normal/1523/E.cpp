#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const int maxn=100000,M=1e9+7;
int n,k,ans;
int p[maxn+10],mp[maxn+10];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=1ll*res*x%M;
        x=1ll*x*x%M;
        y>>=1;
    }
    return res;
}
void reset(){
    p[0]=1;
    for(int i=1;i<=maxn;++i)
        p[i]=1ll*p[i-1]*i%M;
    mp[maxn]=qpow(p[maxn],M-2);
    for(int i=maxn-1;~i;--i)
        mp[i]=1ll*mp[i+1]*(i+1)%M;
}
int C(ll x,ll y){
    if(x<0||y<0||y>x)return 0;
    return 1ll*p[x]*mp[y]%M*mp[x-y]%M;
}
void proc(){
    n=read();k=read();
    //Tk
    ans=0;
    for(int i=1,last=1;i<=n;++i){
        int pval=1ll*C(n-1ll*(k-1)*(i-1),i)%M*p[i]%M*mp[n]%M*p[n-i]%M;
        ans=(ans+1ll*(last-pval+M)*i%M)%M;
        last=pval;
    }
    cout<<ans<<endl;
}
int main(){
    reset();
    int T=read();
    while(T--)proc();
    return 0;
}