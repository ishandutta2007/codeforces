#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int A[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    DEBUG("Hello World!\n");
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 1; i <= n; ++i) {
            int a = i * 2 - 1, b = i * 2;
            if (i & 1) swap(a, b);
            A[i] = a;
            A[i + n] = b;
        }
        printf("YES\n");
        for (int i = 1; i <= 2 * n; ++i) printf("%d ", A[i]);
    }
    else printf("NO\n");
    return 0;
}