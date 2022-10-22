#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=5e5+10;
int a[mn];
ll ans=0;
int pl[mn],pr[mn];
int fl(int x){return x==pl[x]?x:(pl[x]=fl(pl[x]));}
int fr(int x){return x==pr[x]?x:(pr[x]=fr(pr[x]));}
int o[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    iota(pl,pl+mn,0);
    iota(pr,pr+mn,0);
    iota(o,o+mn,0);
    sort(o,o+n,[](int x,int y){return a[x]<a[y];});
    int lo=0,hi=n-1;
    for(int i=0;i<n-2;i++){
        if(o[i]==lo)ans+=a[lo],lo=fr(lo+1);
        else if(o[i]==hi)ans+=a[hi],hi=fl(hi-1);
        else {
            ans += min(a[fr(o[i] + 1)], a[fl(o[i] - 1)]);
            pr[o[i]] = fr(o[i] + 1);
            pl[o[i]] = fl(o[i] - 1);
        }
    }
    printf("%lld",ans);
}