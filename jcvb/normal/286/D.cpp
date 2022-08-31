#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
int n,m;
struct wall{int l,r,t;}w[200005];
int x[400005],xtot=0;
struct node{int x,i;}t[400005];int ttot=0;
int cmp(const node&a,const node&b){
    if(a.i==b.i)return a.x>b.x;
    return a.i<b.i;
}
int mi[400005];
multiset<int> se;
node r[1000005];int rtot=0;
int main()
{
    scanf("%d%d",&m,&n);
    x[xtot++]=0;
    for (int i=1;i<=n;i++)scanf("%d%d%d",&w[i].l,&w[i].r,&w[i].t),x[xtot++]=w[i].l,x[xtot++]=w[i].r;
    sort(x,x+xtot);
    xtot=unique(x,x+xtot)-x-1;
    for (int i=1;i<=n;i++){
        int l=lower_bound(x,x+1+xtot,w[i].l)-x;
        int r=lower_bound(x,x+1+xtot,w[i].r)-x;
        t[++ttot]=(node){w[i].t+1,l};
        t[++ttot]=(node){-w[i].t-1,r};
    }
    sort(t+1,t+1+ttot,cmp);
    for (int i=0,cur=1;i<xtot;i++){
        while(cur<=ttot && t[cur].i==i){
            if(t[cur].x<0){
                multiset<int>::iterator it=se.find(-t[cur].x-1);
                se.erase(it);
            }else{
                se.insert(t[cur].x-1);
            }
            cur++;
        }
        if(!se.empty())mi[i+1]=*se.begin();
        else mi[i+1]=-1;
    }
    for (int i=1;i<=m;i++){
        int q;scanf("%d",&q);
        r[++rtot]=(node){2,q};
        if(i>1 && r[rtot].i<=r[rtot-1].i){
            while(1);
        }
    }
    for (int i=1;i<=xtot;i++)if(~mi[i]){
        r[++rtot]=(node){1,mi[i]-x[i]};
        r[++rtot]=(node){-1,mi[i]-x[i-1]};
    }
    sort(r+1,r+1+rtot,cmp);
    int cur=0,ans=0;
    for (int i=1;i<=rtot;i++){
        ans+=cur*(r[i].i-r[i-1].i);
        if(r[i].x==2)printf("%d\n",ans);
        else cur+=r[i].x;
    }
    return 0;
}