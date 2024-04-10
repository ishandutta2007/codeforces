#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll v[mn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v[x-i+n]+=x;
    }
    ll ans=0;
    for(int i=0;i<mn;i++)ans=max(ans,v[i]);
    printf("%lld",ans);
}