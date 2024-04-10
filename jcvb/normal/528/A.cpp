#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


int w,h,n;

struct opt{
    int type;
    int x;
}a[200005];

int fa[200005];
int cnt[200005];
int ma;
int gf(int &x){
    return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void un(int x,int y){
    x=gf(x);y=gf(y);
    if(x!=y){
        cnt[y]+=cnt[x];
        fa[x]=y;
        ma=max(ma,cnt[y]);
    }
}
void init(int n){
    for (int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
    ma=1;
}
int a1[200005],a2[200005];
int no1[200005],no2[200005];
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    for (int i=1;i<=n;i++){
        char c;while((c=getchar())<'A'||c>'Z');
        scanf("%d",&a[i].x);
        if(c=='V'){
            a[i].type=0;
            no1[a[i].x]=1;
        } else a[i].type=1,no2[a[i].x]=1;
    }
    init(w);
    for (int i=1;i<=w-1;i++)if(!no1[i])un(i,i+1);
    for (int i=n;i>=1;i--){
        a1[i]=ma;
        if(a[i].type==0){
            un(a[i].x,a[i].x+1);
        }
    }
    init(h);
    for (int i=1;i<=h-1;i++)if(!no2[i])un(i,i+1);
    for (int i=n;i>=1;i--){
        a2[i]=ma;
        if(a[i].type==1){
            un(a[i].x,a[i].x+1);
        }
    }
    for (int i=1;i<=n;i++)printf("%I64d\n",1ll*a1[i]*a2[i]);
    return 0;
}