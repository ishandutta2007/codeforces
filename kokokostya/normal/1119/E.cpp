#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    int pointer_odd = n - 1;
    int pointer_need = 0;
    bool ok = true;
    for (int i = n - 1; i >= 0 && ok; i--) {
        pointer_odd = min(i, pointer_odd);
        while (pointer_odd != -1 && a[i] >= 2) {
            if (a[pointer_odd] % 2 == 1) {
                a[pointer_odd]--;
                a[i] -= 2;
                ans++;
            }
            pointer_odd--;
        }
        while(a[i] >= 2) {
            if (a[pointer_need] == 0) {
                pointer_need++;
            }
            if (pointer_need != i) {
                int val = min(a[pointer_need], a[i] / 2);
                a[pointer_need] -= val;
                a[i] -= 2 * val;
                ans += val;
            }
            else {
                ans += a[i] / 3;
                ok = 0;
                break;
            }


        }
    }
    cout << ans << '\n';

    return 0;
}