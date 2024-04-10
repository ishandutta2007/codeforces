#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll>s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        s.insert(x);
    }
    if(n&1^1)s.insert(0);
    ll ans=0;
    while(s.size()>1){
        ll sum=*s.begin()+*(++s.begin())+*(++(++s.begin()));
        s.erase(s.begin()),s.erase(s.begin()),s.erase(s.begin());
        s.insert(sum);
        ans+=sum;
    }
    printf("%lld",ans);
}