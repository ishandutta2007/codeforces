#include <bits/stdc++.h>

using namespace std;

int tab[1000007];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        n *= 2;
        std::vector<int> v;
        bool nieparz = false;
        for (int i = 1; i <= n; i++) {
            scanf("%d", tab + i);
            v.push_back(i);
            if (tab[i] % 2)
                nieparz = !nieparz;
        }
        std::sort(v.begin(), v.end(), [](int a, int b) {
            return (tab[a] % 2) < (tab[b] % 2);
        });
        for (int i = nieparz; i < n - 2; i += 2)
            printf("%d %d\n", v[i], v[i + 1]);
    }
    return 0;
}