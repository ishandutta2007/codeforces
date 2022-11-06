#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int A[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i) cin >> A[i], mx = max(mx, A[i]);
    while (1) {
        int op = 0, me = 0;
        for (int i = 1; i <= n; ++i) {
            op += A[i];
            me += mx - A[i];
        }
        if (op < me) {
            printf("%d\n", mx);
            break;
        }
        ++mx;
    }
    return 0;
}