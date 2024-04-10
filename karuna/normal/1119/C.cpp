#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int a[505][505];
//int b[505][505];
int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &k);
            a[i][j] = a[i][j]^k;
        }
    }

    bool pos = true;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt = 0;
        for (int j=0; j<m; j++) {
            cnt += a[i][j];
        }
        if (cnt%2 == 1) {
            pos = false;
            break;
        }
    }

    for (int j=0; j<m; j++) {
        cnt = 0;
        for (int i=0; i<n; i++) {
            cnt += a[i][j];
        }
        if (cnt%2 == 1) {
            pos = false;
            break;
        }
    }

    if (pos) printf("YES");
    else printf("NO");
}