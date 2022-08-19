// luogu remote judge
#include<bits/stdc++.h>
template<class T>const T&min(const T&a,const T&b){
    if(a<b)
        return a;
    return b;
}
template<class T>const T&max(const T&a,const T&b){
    if(a>b)
        return a;
    return b;
}
const int MAXN=200005;
int n,m,ta,tb,k,ans;
int a[MAXN],b[MAXN];
void kill(){
    puts("-1");
    exit(0);
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)
        scanf("%d",&b[i]);
    if(k>=min(n,m))
        kill();
    for(int i=0,j=1;i<=k;++i){
        for(;j<=m&&b[j]<a[i+1]+ta;++j);
        if(j+k-i>m)
            kill();
        ans=max(ans,b[j+k-i]+tb);
    }
    printf("%d\n",ans);
    return 0;
}