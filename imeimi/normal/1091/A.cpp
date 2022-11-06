#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R, B, Y;
    cin >> Y >> B >> R;
    int mn;
    mn = min({ Y, B - 1, R - 2 });
    printf("%d\n", mn * 3 + 3);
    return 0;
    
}