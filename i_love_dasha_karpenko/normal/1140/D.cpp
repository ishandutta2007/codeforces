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
long long n,res = 0;
int main() {
    //freopen("input.txt","r",stdin);
    cin>>n;
    for (int i = 3;i<=n;i++){
        res+=i*(i-1);
    }
    cout<<res<<endl;
}