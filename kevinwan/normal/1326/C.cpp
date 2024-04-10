#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
ll p[mn],rp[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",p+i),rp[p[i]]=i;
    vector<int>v;
    ll ansa=0,ansb=1;
    for(int i=0;i<k;i++)v.push_back(rp[n-i]),ansa+=n-i;
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        ansb*=v[i]-v[i-1];
        ansb%=mod;
    }
    printf("%lld %lld",ansa,ansb);
}