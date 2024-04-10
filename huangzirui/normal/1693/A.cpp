#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn];
signed main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        int sum=0,is=0;
        while(n && !a[n])--n;
        for(i=1;i<=n;i++){
            sum+=a[i];
            if(sum<0 || (sum==0 && i!=n) || (sum>0 && i==n))is=1;
        }
        if(is)puts("No");
        else puts("Yes");
    }
    return 0;
}