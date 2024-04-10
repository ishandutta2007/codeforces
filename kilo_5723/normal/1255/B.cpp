#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5,maxm=2e3+5;
struct node{
    int val,id;
};
inline bool cmp(const node &a,const node &b){ return a.val<b.val; }
node a[maxn];
int que[maxm][2],siz,ans;
void init(){
    siz=0; ans=0;
}
void store(int i,int j){
    que[siz][0]=a[i].id; que[siz][1]=a[j].id;
    ans+=a[i].val+a[j].val; siz++;
}
void submit(){
    printf("%d\n",ans);
    while (siz--) printf("%d %d\n",que[siz][0],que[siz][1]);
}
int main(){
    int tt;
    int i,n,m;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++){
            scanf("%d",&a[i].val);
            a[i].id=i+1;
        }
        if (n==2||m<n){
            puts("-1"); continue;
        }
        sort(a,a+n,cmp);
        init();
        for (i=0;i<n;i++) store(i,(i+1)%n);
        for (i=n;i<m;i++) store(0,1);
        submit();
    }
    return 0;
}