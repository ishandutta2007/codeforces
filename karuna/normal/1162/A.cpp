#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, h, m;
int maxi[100];
int main() {
    scanf("%d%d%d", &n, &h, &m);

    memset(maxi, -1, sizeof(maxi));
    int l, r, x;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &l, &r, &x);
        for (int i=l; i<=r; i++) {
            if (maxi[i] == -1) maxi[i] = x;
            else maxi[i] = min(maxi[i], x);
        }
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (maxi[i] == -1) cnt += h*h;
        else cnt += maxi[i]*maxi[i];
    }

    printf("%d", cnt);

}