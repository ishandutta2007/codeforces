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
const int maxn=2010,maxm=0,mod=1e9+7;
char s[maxn];
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
void proc(){
    int n,m,c=0,d=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%s",s+1);
        for(int j=1;j<=m;++j)
            if(s[j]=='#')++c;
            else ++d;
    }
    c=qpow(2,c);
    if(!d)c=(c-1+mod)%mod;
    cout<<c<<endl;
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}