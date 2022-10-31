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
long double eps = (long double)(1)/pow(10,8);
long long n,res = 0;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x; char ch; scanf("%c",&ch);
        x = ch-48;
        if (x%2==0)res+=i;
    }
    cout<<res<<endl;
}