#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 1000000000000000007
long long n,C[DIM],V[DIM],flag = 0,root;
vector<long long> A[DIM],T;

void dfs(long long x){
    long long res = C[x];
    for (int i = 0;i<A[x].size();i++){
        res*=C[A[x][i]];
        dfs(A[x][i]);
    }
    if (res==1)T.push_back(x);

}

bool F(long long x){
    for (int i = 0;i<A[x].size();i++){
        if (C[A[x][i]]==0)return false;
    }

    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x,y; scanf("%lld %lld\n",&x,&y);
        if (x==-1){root = i;continue;}
        A[x].push_back(i);
        C[i]=y;
    }
   dfs(root);

    sort(T.begin(),T.end());
    long long k = T.size();
    for (int i = 0;i<k;i++){
        if (T[i]!=root)
            printf("%lld ",T[i]);
    }
    if (T.size()==0){
        printf("-1\n");
    }
}