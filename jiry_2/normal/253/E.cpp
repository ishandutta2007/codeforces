#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct atom{
    int t,s,where;
    double p;
}x[60000];
int n,where,a[60000];
long long T,t[60000];
struct atom2{
    int r,where;
    double w;
};
int operator < (atom2 k1,atom2 k2){
    return k1.w<k2.w;
}
priority_queue<atom2>Q;
int compare(atom k1,atom k2){
    return k1.t<k2.t;
}
long long check(int k){
    x[where].p=k+0.5;
    Q.push((atom2){x[1].s,1,x[1].p}); long long T=x[1].t; int now=2;
    while (1){
        if (Q.empty()&&now>n) return t[where];
        if (!Q.empty()&&(now>n||Q.top().r<=x[now].t-T)){
            t[Q.top().where]=T+Q.top().r; T+=Q.top().r; Q.pop();
        } else {
            if (!Q.empty()){
                atom2 k1=Q.top(); k1.r+=T-(x[now].t); Q.pop(); Q.push(k1);
            }
            Q.push((atom2){x[now].s,now,x[now].p}); T=x[now].t; now++;
        }
    }
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {scanf("%d%d%lf",&x[i].t,&x[i].s,&x[i].p); x[i].where=i;} sort(x+1,x+n+1,compare);
    for (int i=1;i<=n;i++) if (x[i].p==-1) where=i; for (int i=1;i<=n;i++) a[x[i].where]=i;
    scanf("%I64d",&T);
    int l=1,r=1e9,ans=0;
    while (l<r){
        int mid=l+r>>1;
        if (check(mid)>=T) {l=mid+1; ans=mid;} else r=mid;
    }
    check(ans);
    for (int i=1;i<=n;i++) if (x[i].p==ans){ans++; break;} cout<<ans<<endl;
    for (int i=1;i<=n;i++) printf("%I64d ",t[a[i]]); return 0;
}