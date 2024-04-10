#include <bits/stdc++.h>

using namespace std;
#define INF 10E15
#define DIM 100007
#define MAXN 7037000499
typedef pair<long long,long long> pairll;
long long n,a,b,c,P[DIM],maxn,A[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x; scanf("%lld",&A[i]);
        if (A[i]==A[i-1])P[i]=P[i-1]+1;
        else P[i]=0;

    }
    long long res = 1,res2 = 1;
    for (long long i = 1;i<=n;i++){
        if (P[i]>P[i-1])res++;
        else{
            res2 = 1;
            i++;
            while(P[i]>P[i-1]){res2++;i++;}
        }
        maxn = max(maxn,min(res,res2)*2);
        res = res2;
        i--;
    }
    printf("%lld\n",maxn);
}