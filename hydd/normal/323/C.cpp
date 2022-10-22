#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,ans,num[2100000],loc[2100000];
int cnt,rt[2100000],ls[41000000],rs[41000000],sum[41000000];
void change(int &now,int last,int l,int r,int x){
    now=++cnt;
    ls[now]=ls[last]; rs[now]=rs[last]; sum[now]=sum[last]+1;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (x<=mid) change(ls[now],ls[last],l,mid,x);
    else change(rs[now],rs[last],mid+1,r,x);
}
int query(int now,int l,int r,int x,int y){
    if (l==x&&r==y) return sum[now];
    int mid=(l+r)>>1;
    if (y<=mid) return query(ls[now],l,mid,x,y);
    else if (x>mid) return query(rs[now],mid+1,r,x,y);
    else return query(ls[now],l,mid,x,mid)+query(rs[now],mid+1,r,mid+1,y);
}
int f(int x){ return (x-1+ans)%n+1;}

int main(){
    scanf("%d",&n);
    int x,y,l,r;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        loc[x]=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        num[i]=loc[x];
    }
    for (int i=1;i<=n;i++) change(rt[i],rt[i-1],1,n,num[i]);
    scanf("%d",&q);
    while (q--){
        scanf("%d%d%d%d",&x,&y,&l,&r);
        x=f(x); y=f(y); l=f(l); r=f(r);
        if (x>y) swap(x,y);
        if (l>r) swap(l,r);
        ans=query(rt[r],1,n,x,y)-query(rt[l-1],1,n,x,y);
        printf("%d\n",ans++);
    }
    return 0;
}