#include <bits/stdc++.h>

using namespace std;
#define DIM2 507
#define DIM 100007

#define INF 1000000007
const long long MAXN = 1000000007;

typedef pair<long long,long long> pairll;

long long n,k,res = 0,mx=-INF,B[DIM],V[DIM],cres = 0;

vector<long long> A[DIM];

void dfs(long long x){
    if (V[x]==1)return;
    cres++;
    V[x]=1;

    for (int i = 0;i<A[x].size();i++){
        long long k = A[x][i];

        dfs(k);
    }
}
long long flag = 0;

long long p(long long x,long long j){
    long long res = 1;
    for (int i = 1;i<=j;i++){
        res=(res*x) %MAXN;
        //%=MAXN;
    }
    return res;
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&k);
    for (int i = 1;i<n;i++){
        long long x,y,col; scanf("%lld %lld %lld\n",&x,&y,&col);
        if (col==0){
            A[x].push_back(y);
            A[y].push_back(x);
        }


    }

    for (int i = 1;i<=n;i++){
        //memset(V,0,sizeof(V));
        //memset(B,0,sizeof(B));
        cres = 0;
        dfs(i);
        res+=p(cres,k);
        res%=MAXN;
    }
    //cout<<res<<endl;
    long long r =p(n,k);
    if (res>r){
        r = r+1000000007-res;
    }
    else{
        r = r-res;
    }
    cout<<r<<endl;
}