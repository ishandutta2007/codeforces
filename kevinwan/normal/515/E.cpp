#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
ll d[mn],h[mn],pos[mn];
int n,m;
inline int suc(int x){return (x+1)%n;}
inline int pre(int x){return (x-1+n)%n;}
int lo[mn][17],hi[mn][17],bacl[mn],bach[mn];
ll dis(int a,int b){
    if(b>=a)return pos[b]-pos[a];
    else return pos[b]+pos[n]-pos[a];
}
bool inb(int a,int b,int x){
    if(a<=b)return a<=x&&x<=b;
    else return a<=x||x<=b;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",d+i),pos[i+1]=pos[i]+d[i];
    int t=0;
    for(int i=0;i<n;i++)scanf("%lld",h+i),h[i]*=2;
    for(int i=0;i<n;i++)if(h[i]>h[t])t=i;
    memset(lo,-1,sizeof(lo));
    memset(hi,-1,sizeof(hi));
    hi[t][0]=lo[t][0]=t;
    stack<int>q;
    q.push(t);
    for(int i=suc(t);i!=t;i=suc(i)){
        while(q.size()&&h[q.top()]-h[i]-dis(q.top(),i)<0)q.pop();
        if(q.size())hi[i][0]=q.top();
        else hi[i][0]=i;
        bach[hi[i][0]]=i;
        q.push(i);
    }
    while(q.size())q.pop();
    q.push(t);
    for(int i=pre(t);i!=t;i=pre(i)){
        while(q.size()&&h[q.top()]-h[i]-dis(i,q.top())<0)q.pop();
        if(q.size())lo[i][0]=q.top();
        else lo[i][0]=i;
        bacl[lo[i][0]]=i;
        q.push(i);
    }
    for(int i=1;i<17;i++)for(int j=0;j<n;j++)lo[j][i]=lo[lo[j][i-1]][i-1],hi[j][i]=hi[hi[j][i-1]][i-1];
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        int l=suc(b),r=pre(a);
        for(int i=16;i>=0;i--){
            if(!inb(pre(a),b,lo[l][i]))l=lo[l][i];
        }
        for(int i=16;i>=0;i--){
            if(!inb(a,l,hi[r][i]))r=hi[r][i];
        }
        ll ans=dis(l,r)+h[l]+h[r];
        l=suc(b),r=pre(a);
        for(int i=16;i>=0;i--){
            if(!inb(a,suc(b),hi[r][i]))r=hi[r][i];
        }
        for(int i=16;i>=0;i--){
            if(!inb(r,b,lo[l][i]))l=lo[l][i];
        }
        ans=max(ans,dis(l,r)+h[l]+h[r]);
        printf("%lld\n",ans);
    }
}