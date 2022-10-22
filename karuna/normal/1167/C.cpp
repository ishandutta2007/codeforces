#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, x;
int parent[505050];
int sz[505050];
vector<int> a[505050];

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b) {
    if (Find(a) == Find(b)) return;

    a = Find(a);
    b = Find(b);

    parent[b] = a;
    sz[a] = sz[b] = sz[a]+sz[b];

    return;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i=0; i<m; i++) {
        scanf("%d", &k);
        for (int j=0; j<k; j++){
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }

    for (int i=0; i<m; i++) {
        for (auto j : a[i]) {
            Union(a[i][0], j);
        }
    }

    for (int i=1; i<=n; i++) {
        printf("%d ", sz[Find(i)]);
    }
}