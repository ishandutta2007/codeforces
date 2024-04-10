#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[55][55],mx[55],chosen[55],xx[55];

int main()
{
    ll i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%lld",&a[i][j]);
            mx[i]=max(mx[i],a[i][j]);
        }
    }
    for(i=1;i<=n;i++) {
        for(j=0;j<n;j++) {
            if(!chosen[j] && mx[j]<=i) {
                chosen[j]=1;
                xx[j]=i;
                break;
            }
        }
    }
    for(i=0;i<n;i++) printf("%lld ",xx[i]);
}