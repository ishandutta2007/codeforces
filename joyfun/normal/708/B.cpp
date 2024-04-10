#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a, b, c, d;
vector<ll> c1, c2;

bool judge(ll x, ll y) {
    if (b + c != x * y) return false;
    if (x == 0) {
        if (y == 0) return false;
        for (int i = 0; i < y; i++)
            printf("1");
        printf("\n");
        return true;
    }
    if (b % x == 0) {
        ll c = b / x;
        if (c > y) return false;
        for (int i = 0; i < y - c; i++) printf("1");
        for (int i = 0; i < x; i++) printf("0");
        for (int i = 0; i < c; i++) printf("1");
        printf("\n");
        return true;
    }
    ll c = b / x + 1;
    if (c > y) return false;
    ll yu = b % x;
    for (int i = 0; i < y - c; i++) printf("1");
    for(int i = 0; i < yu; i++) printf("0");
    printf("1");
    for (int i = 0; i < x - yu; i++) printf("0");
    for (int i = 0; i < c - 1; i++) printf("1");
    printf("\n");
    return true;
}

int main() {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    for (ll i = 0; i <= 100000; i++) {
        if (i * (i - 1) / 2 == a) c1.push_back(i);
        if (i * (i - 1) / 2 == d) c2.push_back(i);
    }
    for (int i = 0; i < c1.size(); i++) {
        for (int j = 0; j < c2.size(); j++) {
            if (judge(c1[i], c2[j])) {
                return 0;
            }
        }
    }
    printf("Impossible\n");
    return 0;
}