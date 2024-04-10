#include <bits/stdc++.h>

using namespace std;
#define DIM 507

long long n,k,A[DIM],mx = -10000007;
int main()
{
    cin>>n>>k;
    for (int i = 1;i<=n;i++){cin>>A[i];mx = max(mx,A[i]);}
    for (int i = 1;i<=n;i++){
        if (A[i]==mx){
            cout<<fixed<<mx<<endl;
            return 0;
        }
        if (A[i]==-1)continue;
    long long res = 0;
    if (i!=1)res++;
        for (int j = i+1;j<=n;j++){
            if (A[j]<A[i]){A[j] = -1; res++;}
            else break;
        }
        if (res>=k){
            cout<<fixed<<A[i]<<endl;
            return 0;
        }
    }
}