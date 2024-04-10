#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        const int T = 1.1e5;
        vector<int> cnt(T);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < T; i++) ans += cnt[i] % 2;

        if (ans > 0) cout << "Conan" << endl;
        else cout << "Agasa" << endl;
    }

    return 0;
}