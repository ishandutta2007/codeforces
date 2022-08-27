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
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
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
const int mo=1000000007;
const int inf=1061109567;
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
using namespace std;


int n,m;
struct edge{
    int wei,st,id;
}a[111111];

int cmp(const edge&a,const edge&b){
    if(a.wei==b.wei)return a.st>b.st;
    return a.wei<b.wei;
}
int au[111111],av[111111];
inline void ae(int u,int v,int id){
    au[id]=u;
    av[id]=v;
}
int ntot=1;
int st=1,st2=0;

int bu(int id){
    while(st2==0){
        st++;
        st2=st-2;
    }
    if(st>ntot)return 0;
    ae(st,st2,id);
    st2--;
    return 1;
}
int main()
{
    gn(n);gn(m);
    for (int i=1;i<=m;i++)gn(a[i].wei),gn(a[i].st),a[i].id=i;
    sort(a+1,a+1+m,cmp);

    for (int i=1;i<=m;i++){
        if(a[i].st==1){
            ntot++;
            ae(ntot-1,ntot,a[i].id);
        }else{
            if(!bu(a[i].id)){
                printf("-1\n");
                return 0;
            }
        }
    }

    for (int i=1;i<=m;i++)printf("%d %d\n",au[i],av[i]);
    return 0;
}