#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define INF 1000000000007
long long n,A[DIM],k;
int main()
{
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x;scanf("%lld %lld\n",&x,&A[i]);
    }
    sort(A+1,A+1+n);
    scanf("%lld",&k);
    long long res = n;
    for (int i = 1;i<=n;i++){
        if (A[i]<k)res--;
        else break;
    }
    cout<<res<<endl;
}