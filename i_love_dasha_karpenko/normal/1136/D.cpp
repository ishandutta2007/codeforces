#include <bits/stdc++.h>

using namespace std;

#define DIM 500007
#define NOM 500000
#define MAXN 1000007

long long n,m,A[DIM],pointer;
vector<long long> V[DIM];
set<long long> S,F,RF;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    scanf("\n");
    for (int i = 1;i<=m;i++){
        long long x,y;
        scanf("%lld %lld\n",&x,&y);
        if (y==A[n]){
            S.insert(x);
        }
        V[x].push_back(y);
    }
    pointer = n;
    long long res = 0;
    for (int i = n-1;i>=1;i--){

        if (S.count(A[i])!=0){
            RF=F;
            int flag = 0;
            for (int j = 0;j<V[A[i]].size();j++){
                long long k = V[A[i]][j];
                if (F.count(k)!=0){
                    F.erase(k);
                }
                if (k==A[n]){
                    flag = 1;
                }
            }
            if (F.size()>0 || flag==0){
                RF.insert(A[i]);
            }
            else{
                res++;

            }
            F=RF;
        }
        else{
            F.insert(A[i]);
        }
    }

    link:
    printf("%lld\n",res);
}