#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 1000000000000000007
long long n,A[DIM],res1=0,res2=0,sum=0;

bool mycompare(long long a,long long b){
    return a>b;
}
int main()
{
   // freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
        if (A[i]%2==0)res1++;
        if (A[i]%2==1)res2++;
        sum+=A[i];
    }
    sort(A+1,A+1+n,mycompare);
    if (res1>res2)res1=res2+1;
    else if (res2>res1)res2 = res1+1;
    for (int i = 1;i<=n;i++){
        if (A[i]%2==0 && res1>0){
            sum-=A[i]; res1--;
        }
        if (A[i]%2==1 && res2>0){
            sum-=A[i]; res2--;
        }
        if (res1==0 &&res2==0)break;
    }
    cout<<sum<<endl;
}