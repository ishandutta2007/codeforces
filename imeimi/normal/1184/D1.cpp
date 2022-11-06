#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, m, t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m >> t;
    while (t--) {
        int t, i;
        cin >> t >> i;
        if (t == 1) {
            if (i <= k) ++k;
            ++n;
        }
        else {
            if (i < k) {
                k -= i;
                n -= i;
            }
            else n = i;
        }
        printf("%d %d\n", n, k);
    }
    return 0;
}