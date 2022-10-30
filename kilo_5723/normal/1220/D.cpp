#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,maxm=100;
inline int po2(ll n){
    ll ans=0;
    while (!(n&1)){
        ans++; n>>=1;
    }
    return ans;
}
set<ll> st[maxm];
ll a[maxn];
int main(){
    int i,n,p;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%I64d",&a[i]);
        st[po2(a[i])].insert(a[i]);
    }
    p=0;
    for (i=1;i<maxm;i++) if (st[i].size()>st[p].size())
        p=i;
    printf("%d\n",n-st[p].size());
    for (i=0;i<n;i++) if (!st[p].count(a[i])) printf("%I64d ",a[i]);
    puts("");
    return 0;
}