#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=12,maxm=2e3+5;
int n,m;
int ans;
struct arr{
    int a[maxn];
    int mx;
};
arr a[maxm];
inline bool operator < (const arr &a,const arr &b){
    return a.mx>b.mx;
}
inline int add(int a,int b){ a+=b; return a>=n?a-n:a; }
int _que[maxm][maxn],_tmp[maxm][maxn],_val[maxm][maxn];
void dfs(int b[],int p){
    if (p==m) return;
    bool flg=false;
    int i,j,t=a[p].mx;
    for (i=0;i<n;i++) if (b[i]<t){
        flg=true; break;
    }
    if (!flg) return;
    int sum=0;
    for (i=0;i<n;i++) sum+=max(b[i],t);
    if (sum<=ans) return;
    int *c=a[p].a,*que=_que[p],*val=_val[p],*tmp=_tmp[p],siz=0;
    sum=0;
    for (i=0;i<n;i++) sum+=b[i];
    for (i=0;i<n;i++){
        val[i]=0;
        for (j=0;j<n;j++) val[i]+=max(b[j],c[add(i,j)]);
        if (val[i]<=sum) continue;
        que[siz++]=i; ans=max(ans,val[i]);
    }
    sort(que,que+n,[val](int i,int j){ return val[i]>val[j]; });
    for (i=0;i<siz;i++){
        t=que[i];
        for (j=0;j<n;j++) tmp[j]=max(b[j],c[add(j,t)]);
        dfs(tmp,p+1);
    }
}
int main(){
    int tt;
    int i,j;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++) for (j=0;j<m;j++)
            scanf("%d",&a[j].a[i]);
        for (i=0;i<m;i++){
            a[i].mx=0;
            for (j=0;j<n;j++) a[i].mx=max(a[i].mx,a[i].a[j]);
        }
        int b[maxn];
        sort(a,a+m); ans=0;
        for (i=0;i<n;i++) ans+=(b[i]=a[0].a[i]);
        dfs(b,1);
        printf("%d\n",ans);
    }
    return 0;
}