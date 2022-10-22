#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
int p[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        ll a=0,b=0;
        for(int i=0;i<n;i++){
            ll x;
            scanf("%lld",&x);
            a+=x,b^=x;
        }
        a+=b;
        printf("2\n%lld %lld\n",b,a);
    }
}