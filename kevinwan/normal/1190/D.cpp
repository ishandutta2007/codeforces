#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
pii p[mn];
ll fun(ll x){return x*(x+1)/2;}
vector<int>vals;
map<int,int>comp;
int num[mn],bit[mn];
void up(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a++;a;a-=a&-a)b+=bit[a];return b;}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&p[i].second,&p[i].first),vals.push_back(p[i].second);
    sort(vals.begin(),vals.end());
    vals.resize(distance(vals.begin(),unique(vals.begin(),vals.end())));
    for(i=0;i<vals.size();i++)comp[vals[i]]=i;
    for(i=0;i<n;i++)p[i].second=comp[p[i].second],num[p[i].second]++;
    int cur=0;
    ll ans=0,cnt=vals.size();
    sort(p,p+n);
    for(i=0;i<n;i++)up(i,1);
    while(cur!=n){
        ans+=fun(cnt);
        vector<int>v;
        v.push_back(-1);
        for(i=cur;i<n;i++){
            if(p[i].first!=p[cur].first)break;
            v.push_back(p[i].second);
            num[p[i].second]--;
            if(num[p[i].second]==0)cnt--,up(p[i].second,-1);
        }
        v.push_back(vals.size());
        cur=i;
        for(i=0;i<v.size()-1;i++){
            ans-=fun(qu(v[i+1]-1)-qu(v[i]));
        }
    }
    printf("%lld",ans);
}