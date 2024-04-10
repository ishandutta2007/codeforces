#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789


int n,h,w;
char str[555555];
int x[555555],y[555555];
int ind[333];

int firx[1111111],firy[1111111];
int N=500555;

ll mirow[555555],micol[555555];


ll al[1111111];int altot=0;
int cntrow[1111111],cntcol[1111111];
int main()
{
    ind['U']=1;
    ind['R']=0;
    ind['L']=2;
    ind['D']=3;
    gn(n);gn(h);gn(w);
    scanf("%s",str+1);
    x[0]=y[0]=0;
    int maxx=0,mixx=0,mayy=-0,miyy=0;
    for (int i=1;i<=n;i++){
        x[i]=x[i-1]+dx[ind[str[i]]];
        y[i]=y[i-1]+dy[ind[str[i]]];
        maxx=max(maxx,x[i]);
        mixx=min(mixx,x[i]);
        mayy=max(mayy,y[i]);
        miyy=min(miyy,y[i]);
    }
    memset(firx,-1,sizeof(firx));
    memset(firy,-1,sizeof(firy));
    for (int i=0;i<=n;i++){
        if(firx[x[i]+N]==-1)firx[x[i]+N]=i;
        if(firy[y[i]+N]==-1)firy[y[i]+N]=i;
    }
    int W=maxx-mixx+1,H=mayy-miyy+1;
    if(W<=w && H<=h && x[n]==0 && y[n]==0){
        printf("-1\n");
        return 0;
    }
    memset(mirow,63,sizeof(mirow));
    memset(micol,63,sizeof(micol));

    for (int i=1;i<=h;i++){
        if(~firy[-i+N])mirow[i]=min(mirow[i],1ll*firy[-i+N]);
        if(~firy[-i+h+1+N])mirow[i]=min(mirow[i],1ll*firy[-i+h+1+N]);
    }
    for (int i=1;i<=w;i++){
        if(~firx[-i+N])micol[i]=min(micol[i],1ll*firx[-i+N]);
        if(~firx[-i+w+1+N])micol[i]=min(micol[i],1ll*firx[-i+w+1+N]);
    }

    if(x[n]<0){
        for (int i=-x[n]+1;i<=w;i++)micol[i]=min(micol[i],micol[i+x[n]]+n);
    }else if(x[n]>0){
        for (int i=w-x[n];i>=1;i--)micol[i]=min(micol[i],micol[i+x[n]]+n);
    }
    if(y[n]<0){
        for (int i=-y[n]+1;i<=h;i++)mirow[i]=min(mirow[i],mirow[i+y[n]]+n);
    }else if(y[n]>0){
        for (int i=h-y[n];i>=1;i--)mirow[i]=min(mirow[i],mirow[i+y[n]]+n);
    }

    for (int i=1;i<=h;i++)al[++altot]=mirow[i];
    for (int i=1;i<=w;i++)al[++altot]=micol[i];
    sort(al+1,al+1+altot);
    altot=unique(al+1,al+1+altot)-al-1;
    sort(mirow+1,mirow+1+h);
    for (int i=1,j=1;i<=h;i++){
        ll x=mirow[i];
        while(al[j]!=x)j++;
        cntrow[j]++;
    }
    sort(micol+1,micol+1+w);
    for (int i=1,j=1;i<=w;i++){
        ll x=micol[i];
        while(al[j]!=x)j++;
        cntcol[j]++;
    }
    int ans=0;

    int cutrow=0,cutcol=0;
    for (int i=1;i<=altot;i++){
        int num=(1ll*cntcol[i]*(h-cutrow)+1ll*cntrow[i]*(w-cutcol)-1ll*cntcol[i]*cntrow[i])%mo;
        ans=(ans+1ll*num*(al[i]%mo))%mo;
        cutrow+=cntrow[i];
        cutcol+=cntcol[i];
    }
    printf("%d\n",(ans+mo)%mo);
    return 0;
}