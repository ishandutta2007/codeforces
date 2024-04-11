#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        bool cool = true;
        int mx = a[0];
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (diff > a[i]) {
                cool = false;
                break;
            }
            mx = min(mx, a[i] - diff);
            diff = max(diff, a[i] - mx);
            a[i] -= mx;
        }

        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                cool = false;
                break;
            }
        }

        if (cool) puts("YES");
        else puts("NO");
    }


    return 0;
}