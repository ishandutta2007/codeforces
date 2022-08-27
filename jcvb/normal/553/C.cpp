#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int f[222222];
int n,m;
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int u[222222],v[222222];int tot=0;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=2*n;i++)f[i]=i;
    int ans=1;
    while(m--){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        u[++tot]=x;v[tot]=y;
        if(c){
            if(gf(x)==gf(y+n)||gf(y)==gf(x+n)){
                ans=0;
                break;
            }
            f[gf(x)]=gf(y);
            f[gf(x+n)]=gf(y+n);
        }else{
            if(gf(x)==gf(y)||gf(y+n)==gf(x+n)){
                ans=0;
                break;
            }
            f[gf(x)]=gf(y+n);
            f[gf(x+n)]=gf(y);
        }
    }
    if(ans==0){
        printf("0\n");
    }else{
        for (int i=1;i<=n;i++)f[i]=i;
        int cnt=n;
        for (int i=1;i<=tot;i++){
            int x=gf(u[i]),y=gf(v[i]);
            if(x!=y){
                f[x]=y;
                cnt--;
            }
        }
        int ans=qp(2,cnt-1);
        printf("%d\n",ans);

    }
    return 0;
}