#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
void mult(ll &a,ll b){
    if(a>=inf/b)a=inf;
    else a*=b;
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,mult(a,a))if(b&1)mult(ans,a);
    return ans;
}
int pr[]={2,3,5,7,11,13,17,19,23,29,31};
ll solve(int n,int p,int l){
    if(n==1)return 1;
    ll ans=inf;
    for(int i=l;i>=2;i--){
        if(n%i==0){
            ll bes=solve(n/i,p+1,i);
            mult(bes,po(pr[p],i-1));
            ans=min(ans,bes);
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    printf("%lld",solve(n,0,1000));
}