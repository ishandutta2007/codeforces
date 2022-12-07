#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll a;

int main() {
    scanf("%lld", &a);
    ll num = INF / 10 % a;
    num = num * 2 % a;
    num = num * 9 % a;
    num = num * 9 % a;
    num = num * 5 % a;
    printf("%lld %lld\n", a - num, a - num + INF - 1);
    return 0;
}