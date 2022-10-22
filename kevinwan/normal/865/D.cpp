#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    priority_queue<ll>pq;
    ll ans=0;
    while(n--){
        ll x;
        scanf("%lld",&x);
        if(pq.size()&&pq.top()+x>0){
            ans+=pq.top()+x;
            pq.pop();
            pq.push(-x);
        }
        pq.push(-x);
    }
    printf("%lld",ans);
}