#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int maxx = 2010;
struct node{
    ll x,y,z,k;
}a[maxx];
int flag[maxx];
int main()
{
    int n,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(flag[i] == 1){
            continue ;
        }
        flag[i] = 1;
        ll minn = 1e18;
        int minnj;
        for(int j=1;j<=n;j++){
            if(flag[j] == 1){
                continue ;
            }
            ll now = 1ll*(a[j].x - a[i].x)*1ll*(a[j].x - a[i].x) +
            1ll*(a[j].y - a[i].y)*1ll*(a[j].y - a[i].y) + 1ll*(a[j].z - a[i].z)*1ll*(a[j].z -a[i].z);
            //cout<<now<<endl;
            if(now < minn){
                minn = now;
                minnj = j;
            }
        }
        flag[minnj] = 1;
        printf("%d %d\n",i,minnj);
        cnt+=2;
        if(cnt == n){
            break;
        }
    }
    return 0;
}