#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, a, b, c;
ll ans;

int main(){
    scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    if(a < b - c || n < b) printf("%I64d", n / a);
    else{
        ans += (n - c) / (b - c);
        ans += (n - (b - c) * ans) / a;
        printf("%I64d", ans);
    }
}