#include <bits/stdc++.h>

using namespace std;
#define DIM2 507
#define DIM 300007

#define INF 10E18
#define MAXN 10007
typedef pair<long long,long long> pairll;
struct troinik{
    long long b,w,t;
};
long long n,k,F[DIM],minq;
pairll A[DIM];
vector<pairll> B;
bool mycompare(pairll a,pairll b){
    return a.second<b.second;
}

priority_queue<long, vector<long>, greater<long> > Q;
long long sum = 0;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&k);
    //B.resize(n+7);
    for (int i = 1;i<=n;i++){
        long long x,y; scanf("%lld %lld\n",&x,&y);
        A[i]={y,x};
        //B.push_back({x,y});
    }
    sort(A+1,A+1+n);
    //sort(B.begin(),B.end());
    long long res = 0;
    for (int i = n;i>=1;i--){
        Q.push(A[i].second);
        sum+=A[i].second;
        while (Q.size()>k){
            sum-=Q.top();
            Q.pop();
        }
        res = max(res,sum*A[i].first);
    }

    printf("%lld\n",res);
}