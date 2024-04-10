//#pragma comment(linker, "/STACK:2000000000")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll h[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>h[i],h[i]-=i;
    deque<pll>dq;
    dq.push_front({h[0],1});
    for(int i=1;i<n;i++){
        while(dq.size()>=2&&h[i]-dq[0].first>=dq[0].second){
            h[i]-=dq[0].second;
            dq[1].second+=dq[0].second;
            dq.pop_front();
        }
        if(h[i]<dq[0].first){
            dq.push_front({h[i],1});
            continue;
        }
        if(dq.size()>=2){
            ll r=h[i]-dq[0].first;
            dq[1].second+=r,dq[0].second-=r;
            h[i]-=r;
        }
        else{
            ll k=(h[i]-dq[0].first)/(dq[0].second+1),r=(h[i]-dq[0].first)%(dq[0].second+1);
            if(r==dq[0].second)k++,r=0;
            h[i]-=dq[0].second*k+r,dq[0].first+=k;
            if(r)dq.push_back({dq[0].first+1,r}),dq[0].second-=r;
            assert(dq[0].second);
        }
        if(h[i]==dq[0].first)dq[0].second++;
        else dq.push_front({h[i],1});
    }
    for(int i=n-1,j=0;j<dq.size();j++)for(int k=0;k<dq[j].second;k++,i--)h[i]=dq[j].first;
    for(int i=0;i<n;i++)printf("%lld ",h[i]+i);
}