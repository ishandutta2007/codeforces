#include <bits/stdc++.h>

using namespace std;
#define DIM 20
long long n,A[DIM],mx=0,F[DIM];
int main()
{
   scanf("%lld\n",&n);
   for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);

   }
   F[n]=1;
   for (int i = n-1;i>=1;i--){
        if (A[i]<=A[i+1])F[i]=F[i+1]+1;
        else F[i]=1;
   }
   for (int i = n;i>=1;i/=2){
        for (int j = 1;j<=n;j+=i){
            if (F[j]>=i){
                cout<<i<<endl;
                return 0;
            }
        }
   }
   cout<<mx<<endl;

}