#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,t,sz,p[4],f[8005][8005],h[110000];
inline int hs(int x,int y){ x+=(n+1); y+=(n+1); return (x-1)*t+y;}
inline int dis2(int x,int y){ return x*x+y*y;}
inline void MINUS(int &x,int y){ x-=y; if (x<0) x+=Mod;}
ll qpow(ll x,int a){
    ll res=1;
    while (a){
        if (a&1) res=res*x%Mod;
        x=x*x%Mod; a>>=1;
    }
    return res;
}
void Gauss(){
    for  (int i=1;i<=sz;i++){
        int inv=qpow(f[i][i],Mod-2);
        for (int j=i+1;j<=min(i+1+t,sz);j++) f[i][j]=1ll*f[i][j]*inv%Mod;
        f[i][sz+1]=1ll*f[i][sz+1]*inv%Mod; f[i][i]=1ll;
        for (int j=i+1;j<=min(i+1+t,sz);j++){
            if (!f[j][i]) continue;
            for (int k=i+1;k<=min(i+1+t,sz);k++) MINUS(f[j][k],1ll*f[j][i]*f[i][k]%Mod);
            MINUS(f[j][sz+1],1ll*f[j][i]*f[i][sz+1]%Mod);
            f[j][i]=0ll;
        }
    }
    int to=h[hs(0,0)];
    for (int i=sz;i>=to;i--){
        int inv=qpow(f[i][i],Mod-2);
        f[i][sz+1]=1ll*f[i][sz+1]*inv%Mod;
        for (int j=i-1;j>=to;j--) MINUS(f[j][sz+1],1ll*f[j][i]*f[i][sz+1]%Mod);
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&p[0],&p[1],&p[2],&p[3]); t=2*n+1;
    int lim=n*n,s=p[0]+p[1]+p[2]+p[3];
    sz=0;
    for (int i=-n;i<=n;i++)
        for (int j=-n;j<=n;j++)
        	if (dis2(i,j)<=lim) h[hs(i,j)]=++sz;
    for (int i=-n;i<=n;i++)
        for (int j=-n;j<=n;j++){
            int now=h[hs(i,j)]; //printf("now:%d\n",now);
            if (dis2(i,j)<=lim){
            	MINUS(f[now][now],s);
                MINUS(f[now][sz+1],s);
                for (int k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if (dis2(x,y)<=lim) f[now][h[hs(x,y)]]=p[k];
                }
            }
        }
    Gauss();
    printf("%d\n",f[h[hs(0,0)]][sz+1]);
    return 0;
}