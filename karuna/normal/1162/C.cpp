#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int query[101010];
int arr[101010];
int f[101010];
int l[101010];

int main() {
    scanf("%d%d", &n, &m);

    for (int i=0; i<m; i++) {
        scanf("%d", &query[i]);
    }

    memset(f, -1, sizeof(f));
    memset(l, -1, sizeof(l));

    for (int i=0; i<m; i++) {
        if (f[query[i]] == -1) f[query[i]] = i;
        l[query[i]] = i;
    }

    for (int i=0; i<m; i++) {
        if (f[query[i]] != i) continue;

        if (query[i] != 1 && i > l[query[i]-1]) arr[query[i]]++;
        if (query[i] != n && i > l[query[i]+1]) arr[query[i]]++;
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (f[i]!=-1) ans += arr[i];
        else {
            if (i==1 || i==n) ans += 2;
            else ans += 3;
        }
    }

    printf("%d", ans);

}