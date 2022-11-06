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
pll A[7001];
vector<int> edge[7001];
int indeg[7001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i].fs;
    llong sum = 0;
    for (int i = 1; i <= n; ++i) cin >> A[i].se, sum += A[i].se;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if ((A[i].fs & A[j].fs) == A[j].fs) edge[i].push_back(j), ++indeg[j];
        }
    }
    vector<int> st;
    for (int i = 1; i <= n; ++i) if (indeg[i] == 0) st.push_back(i);
    for (int it = 0; it < (int)st.size(); ++it) {
        int x = st[it];
        sum -= A[x].se;
        for (int i : edge[x]) {
            if (--indeg[i] == 0) {
                st.push_back(i);
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}