#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5e5+10;
const ll mod=1e6+3;
typedef pair<ll,ll>pll;
pll a[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i].first);
    for(int i=0;i<n;i++)scanf("%lld",&a[i].second);
    sort(a,a+n);
    a[n].first=0x3f3f3f3f;
    priority_queue<ll>pq;
    ll lv=0,sum=0,ans=0;
    lv=a[0].first-1;
    for(int i=0;i<n;i++){
            pq.push(a[i].second),sum+=a[i].second;
        if(a[i].first!=a[i+1].first){
            while(pq.size()&&lv<a[i+1].first-1){
                ++lv;
                sum-=pq.top();
                pq.pop();
                ans+=sum;
            }
            lv=a[i+1].first-1;
        }
    }
    printf("%lld",ans);
}