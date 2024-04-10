#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


int n,k;

char b[4][211];

int qux[10055],quy[10055],p,q;
int vis[4][211];



int vali(int x,int y,int i){
    if(y+3>200)return 0;
    if(b[x][y+1]!='.')return 0;
    if(b[i][y+1]!='.')return 0;
    if(b[i][y+2]!='.')return 0;
    if(b[i][y+3]!='.')return 0;
    return 1;
}
int main()
{
    int tes;scanf("%d",&tes);
    while(tes--){
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&k);
        for (int i=1;i<=3;i++){
            scanf("%s",b[i]+1);
            for (int j=n+1;j<=200;j++)b[i][j]='.';
        }
        int ix,iy;
        for (int i=1;i<=3;i++)
            for (int j=1;j<=n;j++)if(b[i][j]=='s'){
                ix=i,iy=j;
                break;
            }
        p=q=0;
        qux[q]=ix,quy[q++]=iy;
        vis[ix][iy]=1;
        while(p!=q){
            int ux=qux[p],uy=quy[p++];
            for (int i=1;i<=3;i++)if(!vis[i][uy+3] && vali(ux,uy,i) && abs(ux-i)<=1){
                qux[q]=i,quy[q++]=uy+3;
                vis[i][uy+3]=1;
            }
        }
        int bo=0;
        for (int i=150;i<=200;i++)
            for (int j=1;j<=3;j++)if(vis[j][i])bo=1;
        if(bo)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}