#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

int l[307], c[307];
std::map<int, long long> koszty;
std::set<int> mozliwe;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &l[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &c[i]);

    for (int i = 0; i < N; i++) {
        for (auto it : mozliwe) {
            int g = std::__gcd(l[i], it);
            if (koszty.count(g) != 0)
                koszty[g] = std::min(koszty[g], koszty[it] + c[i]);
            else
                koszty[g] = koszty[it] + c[i];
            mozliwe.insert(g);
        }
        mozliwe.insert(l[i]);
        if (koszty.count(l[i]) == 0)
            koszty[l[i]] = c[i];
        else
            koszty[l[i]] = std::min(koszty[l[i]], (long long) c[i]);
    }
    if (mozliwe.count(1) == 0) {
        printf("-1");
        return 0;
    }
    printf("%I64d\n", koszty[1]);
    return 0;
}