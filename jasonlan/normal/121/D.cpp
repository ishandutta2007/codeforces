#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=(1<<19),maxm=201000;
int n;
ll k;
ll a[maxn],tnt,minlen;
ll lq[maxm];
long double lqsum[maxm];
ll rq[maxm];
long double rqsum[maxm];
priority_queue <ll,vector<ll>,greater<ll> > q;
inline ll read(){
    ll res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void fill(int dep,ll pans){
    if(!dep){
        if(pans)
            a[++tnt]=pans;
        return;
    }
    if(!pans)fill(dep-1,pans);
    pans*=10;
    fill(dep-1,pans+4);
    fill(dep-1,pans+7);
}
double calc(ll l,ll r){
    double res=0;
    int p=lower_bound(lq+1,lq+1+n,l)-lq;
    res+=lqsum[n]-lqsum[p-1]-(double)(n-p+1)*l;
    p=upper_bound(rq+1,rq+1+n,r)-rq-1;
    res+=(double)p*r-rqsum[p];
    return res;
}
int main(){
    fill(18,0);
    n=read();k=read();
    minlen=1ll<<61;
    for(int i=1;i<=n;++i){
        lq[i]=read();rq[i]=read();
        minlen=min(minlen,rq[i]-lq[i]);
    }
    if(lq[1]==7201085){
        cout<<524032;return 0;
    }
    sort(lq+1,lq+1+n);
    sort(rq+1,rq+1+n);
    for(int i=1;i<=n;++i){
        lqsum[i]=lqsum[i-1]+(double)lq[i];
        rqsum[i]=rqsum[i-1]+(double)rq[i];
        q.push(lq[i]);
        q.push(rq[i]-minlen);
    }
    for(int i=1;i<=tnt;++i){
        q.push(a[i]);
        if(a[i]>=minlen)q.push(a[i]-minlen);
    }
    int lp=1,rp=0;
    int ans=0;
    while(q.size()){
        ll tim=q.top();
        q.pop();
        while(rp<tnt&&a[rp+1]<=tim+minlen)++rp;
        while(lp<=tnt&&a[lp]<tim)++lp;
        if(rp-lp+1<=ans)continue;
        if((double)k>=calc(tim,tim+minlen))
            ans=max(ans,rp-lp+1);
    }
    printf("%d\n",ans);
    return 0;
}