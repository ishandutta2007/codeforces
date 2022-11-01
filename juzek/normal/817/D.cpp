#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    int N;
    scanf("%d", &N);
    int a;
    std::vector<std::pair<int, int>> pos;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        pos.emplace_back(a, i);
    }
    std::sort(pos.begin(), pos.end());
    std::set<int> ter;
    ter.insert(0);
    ter.insert(N + 1);
    long long wyn = 0;
    for (auto it = pos.begin(); it != pos.end(); it++) {
        auto prev = ter.lower_bound(it->second), next = prev--;
        wyn -= (long long) it->first * (it->second - *prev) * (*next - it->second);
        ter.insert(it->second);
    }
    ter.clear();
    ter.insert(0);
    ter.insert(N + 1);
    for (auto it = pos.rbegin(); it != pos.rend(); it++) {
        auto prev = ter.lower_bound(it->second), next = prev--;
        wyn += (long long) it->first * (it->second - *prev) * (*next - it->second);
        ter.insert(it->second);
    }
    printf("%lld", wyn);
    return 0;
}