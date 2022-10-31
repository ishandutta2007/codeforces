#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 1000000000000000007
long long n,A[DIM],res1=0,res2=0,sum=0;
map<long long,int> S;
bool mycompare(long long a,long long b){
    return a>b;
}
vector<long long> x,y;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    sort(A+1,A+1+n);
    for (int i = 1;i<=n;i++){
        if (S.count(A[i])==1 && S[A[i]]>=2){
            printf("NO\n");
            return 0;
        }
        if (S.count(A[i])==0){
            S[A[i]]=1;
            x.push_back(A[i]);
        }
        else if (S.count(A[i])==1 && S[A[i]]==1){
            S[A[i]]++;
            y.push_back(A[i]);
        }

    }
    long long k1 = x.size(),k2 = y.size();
    printf("YES\n%d\n",x.size());
    for (int i = 0;i<k1;i++)printf("%lld ",x[i]);
    printf("\n%d\n",y.size());
    for (int i = k2-1;i>=0;i--)printf("%lld ",y[i]);
    printf("\n");
}