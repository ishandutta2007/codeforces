#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll s[mn],d[mn],val[mn];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",s+i);
    sort(s,s+n);
    for(i=0;i<n-1;i++)d[i+1]=s[i+1]-s[i];
    sort(d,d+n);
    int q;
    scanf("%d",&q);
    for(i=1;i<n;i++){
        val[i]=val[i-1]+(d[i]-d[i-1])*(n-i+1);
    }
    while(q--){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        r-=l-1;
        int cur=0;
        for(i=1<<16;i;i>>=1){
            if(cur+i>=n)continue;
            if(d[cur+i]<=r)cur+=i;
        }
        printf("%lld ",val[cur]+(r-d[cur])*(n-cur));
    }
}