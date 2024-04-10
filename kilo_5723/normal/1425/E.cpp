#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],d[maxn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&d[i]);
    ll ans=0;
    if (k>=2){
        ll sum=0; int mnm=1e9;
        for (int i=0;i<n;i++) sum+=a[i];
        for (int i=0;i<n-1;i++) mnm=min(mnm,d[i]);
        ans=max(sum-mnm,(ll)a[n-1]-d[n-1]);
    }
    else if (k){
        ll sum=0;
        for (int i=n-1;i;i--){
            sum+=a[i]; ans=max(ans,sum-d[i]);
        }
        sum+=a[0];
        for (int i=0;i<n-1;i++) ans=max(ans,sum-a[n-1]-d[i]);
        for (int i=1;i<n-1;i++) ans=max(ans,sum-a[i]-d[0]);
        sort(d,d+n);
        ans=max(ans,sum-d[0]-d[1]);
    }
    else {
        ll sum=0;
        for (int i=n-1;i>=0;i--){
            sum+=a[i]; ans=max(ans,sum-d[i]);
        }
    }
    printf("%lld\n",max(ans,0LL));
    return 0;
}