#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong a, b, c;
    cin >> a >> b >> c;
    if (a < b) b = min(a + 1, b);
    if (a > b) a = min(a, b + 1);
    printf("%lld\n", a + b + c + c);
    return 0;
}