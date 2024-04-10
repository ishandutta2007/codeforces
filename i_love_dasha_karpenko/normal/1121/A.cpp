
#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 1000000000007
typedef pair<long long,long long> pairll;
long long n,m,k,P[DIM],S[DIM],res=0;
priority_queue<long long> A[DIM],Q;
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    for (int i = 1;i<=n;i++)cin>>P[i];
    for (int i = 1;i<=n;i++){
        long long x; cin>>x;
        S[i]=x;
        A[x].push(P[i]);
    }
    for (int i = 1;i<=k;i++){
        long long x; cin>>x; Q.push(x);
    }
    while(!Q.empty()){
        long long t = Q.top(); Q.pop();
        if (P[t]!=A[S[t]].top())res++;
    }
    cout<<res<<endl;

}