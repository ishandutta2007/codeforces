#include <bits/stdc++.h>

using namespace std;
#define INF 10E15
#define DIM 200007
long long n,cres = 1000,mi = 1000,start,R[DIM],A[DIM];
set<long long> M;
int main()
{
    scanf("%lld\n",&n);
    //printf("%lld ",cres);

    for (int i = 1;i<n;i++){
        scanf("%lld",&A[i]);
        cres+=A[i];
        mi = min(cres,mi);
    }
    start = 1000-mi+1;
    R[1]=start;
    if (M.count(start)!=0 || start>n || start<1){
            printf("-1\n");
            return 0;
        }
    M.insert(start);
    for (int i = 1;i<n;i++){
        start+=A[i];
        if (M.count(start)!=0 || start>n || start<1){
            printf("-1\n");
            return 0;
        }
        M.insert(start);
        R[i+1]=start;
    }

    for (int i = 1;i<=n;i++){
        printf("%lld ",R[i]);
    }

}