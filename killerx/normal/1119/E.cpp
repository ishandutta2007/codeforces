#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    ll ans=0;
    int j=0;
    for(int i=0;i<n;++i){
        while(j<i){
            ll cur=min(a[j],a[i]/2);
            ans+=cur;
            a[j]-=cur;
            a[i]-=2*cur;
            if(a[i]<2)break;
            ++j;
        }
        ans+=a[i]/3;
        a[i]%=3;
    }
    printf("%lld\n",ans);
    return 0;
}