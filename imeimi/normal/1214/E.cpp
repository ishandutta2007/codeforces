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
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
int D[100001];
int A[200005];
vector<int> C[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> ord;
    for (int i = 1; i <= n; ++i) {
        cin >> D[i];
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return D[a] > D[b];
    });
    for (int i = 0; i < n; ++i) {
        A[i + 1] = (ord[i] << 1) - 1;
    }
    for (int i = 0; i < n; ++i) {
        int x = ord[i];
        int d = D[x];
        if (A[i + d] > 0) {
            if (A[i + d + 1] > 0) {
                C[i + d].push_back(x + x);
            }
            else A[i + d + 1] = x + x;
        }
        else {
            return 1;
        }
    }
    for (int i = 2; A[i] > 0; ++i) {
        printf("%d %d\n", A[i - 1], A[i]);
    }
    for (int i = 1; A[i] > 0; ++i) {
        for (int j : C[i]) {
            printf("%d %d\n", A[i], j);
        }
    }
    return 0;
}