#include<bits/stdc++.h>
using namespace std;
int n,ans,a[210000],tree[410000];
int f[210000],g[210000];
int cnt,num[410000];
void add(int x,int y){
    for (;x<=cnt;x+=x&-x) tree[x]=max(tree[x],y);
}
int query(int x){
    int res=0;
    for (;x;x-=x&-x) res=max(res,tree[x]);
    return res;
}
int main(){
    scanf("%d",&n); cnt=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]),a[i]-=i;
        num[++cnt]=a[i]; num[++cnt]=a[i]+1;
    }
    sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
    for (int i=1;i<=n;i++) a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;

    memset(tree,0,sizeof(tree));
    for (int i=1;i<=n;i++){
        f[i]=query(a[i])+1;
        ans=max(ans,f[i]+1);
        add(a[i],f[i]);
    }

    memset(tree,0,sizeof(tree));
    for (int i=n;i>=1;i--){
        g[i]=query(cnt-a[i]+1)+1;
        ans=max(ans,g[i]+1);
        add(cnt-a[i]+1,g[i]);
    }

    memset(tree,0,sizeof(tree));
    for (int i=1;i<=n;i++){
        ans=max(ans,query(a[i]+1)+g[i]+1);
        if (i>1) add(a[i-1],f[i-1]);
    }

    printf("%d\n",max(0,n-ans));
    return 0;
}