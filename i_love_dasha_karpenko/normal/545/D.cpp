#include <bits/stdc++.h>
using namespace std;
#define DIM 100007
#define INF 1000000000000000007
#define MAXNUM 107
long long n,A[DIM],ct=0,res = 0;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++)scanf("%lld",&A[i]);
    sort(A+1,A+1+n);
    for (int i = 1;i<=n;i++){
        link:
        if (i>n)break;
        if (A[i]>=ct){
            res++;
            ct+=A[i];
        }
        else{
            i++;

            goto link;
        }
    }
    printf("%lld\n",res);
}