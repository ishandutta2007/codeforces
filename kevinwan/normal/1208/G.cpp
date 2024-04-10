#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll tot[mn];
int main() {
    iota(tot,tot+mn,0);
    int i,j;
    for(i=2;i<mn;i++){
        if(tot[i]==i){
            for(j=i;j<mn;j+=i){
                tot[j]/=i;
                tot[j]*=i-1;
            }
        }
    }
    int n,k;
    scanf("%d%d",&n,&k);
    sort(tot+3,tot+n+1);
    ll ans=0;
    for(i=3;i<3+k;i++)ans+=tot[i];
    printf("%lld",ans+1+(k>=2));
}