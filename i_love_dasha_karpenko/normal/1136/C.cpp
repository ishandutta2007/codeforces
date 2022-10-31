#include <bits/stdc++.h>

using namespace std;

#define DIM 1000007
#define NOM 500000
#define MAXN 1000007

long long n,m;
vector<long long> A[DIM],B[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&m);
    for (int i= 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            long long x;
            scanf("%lld",&x);
            A[i+j-1].push_back(x);
        }
        scanf("\n");
    }
    for (int i= 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            long long x;
            scanf("%lld",&x);
            B[i+j-1].push_back(x);
        }
        scanf("\n");
    }
    for (int i = 1;i<n+m;i++){
        sort(A[i].begin(),A[i].end());
        sort(B[i].begin(),B[i].end());
        for (int j = 0;j<A[i].size();j++){
            if (A[i][j]!=B[i][j]){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}