#include <bits/stdc++.h>
using namespace std;
const long long maxN = 200000;
long long arr[maxN];
 
signed main(){
    long long n,h;
    cin>>n>>h;
    for (long long i=1; i<=n; ++i) cin>>arr[i];
    long long ans=0;
    for (long long i=1; i<=n; ++i){
        sort(arr+1,arr+i+1);
        long long k=0;
        for (long long j=2; j<=i; j+=2){
            k+=arr[j];
        }
        long long k0=0;
        for (long long j=i; j>0; j-=2){
            k0+=arr[j];
        }
        if (i%2) k+=arr[i];
        if (k<=h || k0<=h) ans=i;
    }
    cout<<ans<<endl;
}