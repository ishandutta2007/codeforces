#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, m;
int deg[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    if (m == (llong)n * (n - 1) / 2) {
        printf("NO\n");
        return 0;
    }
    set<pii> sp;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        ++deg[x];
        ++deg[y];
        sp.emplace(x, y);
    }
    int A = -1, B = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (sp.find(pii(i, j)) == sp.end()) {
                A = i; B = j; break;
            }
        }
        if (A != -1) break;
    }
    printf("YES\n");
    int x = 2;
    for (int i = 1; i <= n; ++i) {
        if (i == A) printf("1 ");
        else if (i == B) printf("2 ");
        else printf("%d ", ++x);
    }
    printf("\n");
    x = 2;
    for (int i = 1; i <= n; ++i) {
        if (i == A || i == B) printf("1 ");
        else printf("%d ", ++x);
    }
    printf("\n");
    return 0;
}