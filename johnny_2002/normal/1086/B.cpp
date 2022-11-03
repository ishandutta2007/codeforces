#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define X first
#define Y second

int deg[100005];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        deg[x]++, deg[y]++;
    }
    int n1 = count(deg + 1, deg + n + 1, 1);
    printf("%.9f", 2 * (m + .0) / n1);
}