#include<cstdio>
#include<algorithm>
#include<cassert>
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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;
const int inf=2147483647;
int n,len;
struct item{
    int cost,val,t;
}a[4444];
int cmpi(const item&a,const item&b){
    return a.t<b.t;
}
struct qry{
    int l,sz,id;
}que[24444];int q;

int cmpq(const qry&a,const qry&b){
    return a.l<b.l;
}
vector<int>it[53333];
int ans[24444];
int lisl[4444],totl;
int lisr[4444],totr;
int f[4444][4444],g[4444][4444];
void workl(int i){
    totl=0;
    for (int j=i*len;j>(i-1)*len;j--)
        for (int k=0;k<it[j].size();k++)lisl[++totl]=it[j][k];
    f[0][0]=0;
    for (int j=1;j<=totl;j++){
        for (int k=0;k<=4000;k++)f[j][k]=max(f[j-1][k],k>=a[lisl[j]].cost?f[j-1][k-a[lisl[j]].cost]+a[lisl[j]].val:0);
    }
}
void workr(int i){
    totr=0;
    for (int j=i*len+1;j<(i+1)*len;j++)
        for (int k=0;k<it[j].size();k++)lisr[++totr]=it[j][k];
    g[0][0]=0;
    for (int j=1;j<=totr;j++){
        for (int k=0;k<=4000;k++)g[j][k]=max(g[j-1][k],k>=a[lisr[j]].cost?g[j-1][k-a[lisr[j]].cost]+a[lisr[j]].val:0);
    }
}
int main()
{
    gn(n);gn(len);
    for (int i=1;i<=n;i++){
        gn(a[i].cost);
        gn(a[i].val);
        gn(a[i].t);
        a[i].t+=len-1;
    }
    sort(a+1,a+1+n,cmpi);
    for (int i=1;i<=n;i++)it[a[i].t].push_back(i);
    gn(q);
    for (int i=1;i<=q;i++)gn(que[i].l),gn(que[i].sz),que[i].id=i;
    sort(que+1,que+1+q,cmpq);
    for (int i=1,cur=1;i*len<=que[q].l+len-1;i++){
        workl(i);workr(i);
        while(cur<=q && que[cur].l>(i-1)*len && que[cur].l<=i*len){
            int an=0;
            int le=0,ri=0;
            while(le+1<=totl && a[lisl[le+1]].t>=que[cur].l)le++;
            while(ri+1<=totr && a[lisr[ri+1]].t<=que[cur].l+len-1)ri++;
            for (int j=0;j<=que[cur].sz;j++)an=max(an,f[le][j]+g[ri][que[cur].sz-j]);
            ans[que[cur].id]=an;
            cur++;
        }
    }
    for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}