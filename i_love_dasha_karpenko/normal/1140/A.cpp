#include <bits/stdc++.h>

using namespace std;
#define DIM2 507
#define DIM 100007

#define INF 10E18
#define MAXN 10007
typedef pair<long long,long long> pairll;
struct troinik{
    long long b,w,t;
};
long long n,res = 0;
set<long long> S;
priority_queue<long long> Q;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x;scanf("%lld",&x);
        Q.push(x);
        //cout<<Q.top()<<endl;
        if (Q.top()==i){
            while(!Q.empty())Q.pop();
            res++;
        }
    }
    cout<<res<<endl;
}