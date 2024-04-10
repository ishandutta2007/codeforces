#include <bits/stdc++.h>

using namespace std;
#define INF 100000000000007
#define DIM 100007
typedef pair<long long,long long> pairll;
long long n,A[DIM],maxnum=-INF,res=0;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
        maxnum = max(maxnum,A[i]);
    }
    long long cres=0;
    for (int i = 1;i<=n;i++){

        if (A[i]==maxnum)cres++;
        else cres=0;
        if (cres>res)res=cres;
    }
    printf("%lld\n",res);
}