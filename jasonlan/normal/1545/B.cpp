#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010,maxm=0,mod=998244353;
int n;
char s[maxn];
int p[maxn],mp[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int qpow(int x,int k){
    int res=1;
    while(k){
        if(k&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        k>>=1;
    }
    return res;
}
void reset(){
    p[0]=1;
    for(int i=1;i<=100000;++i)
        p[i]=p[i-1]*(1ll*i)%mod;
    mp[100000]=qpow(p[100000],mod-2);
    for(int i=99999;~i;--i)
        mp[i]=mp[i+1]*(1ll*(i+1))%mod;
}
int C(int x,int y){
    if(x<y||x<0||y<0)return 0;
    return 1ll*p[x]*mp[y]%mod*mp[x-y]%mod;
}
void proc(){
    n=read();
    scanf("%s",s+1);
    int cnt=0,cnt0=0;
    for(int i=n;i>1;){
        if(s[i]=='0'||s[i-1]!='1')--i;
        else{
            ++cnt;i-=2;
        }
    }
    for(int i=n;i;--i)
        if(s[i]=='0')++cnt0;
    printf("%d\n",C(cnt0+cnt,cnt));
}
int main(){
    reset();
    int T=read();
    while(T--)proc();
    return 0;
}