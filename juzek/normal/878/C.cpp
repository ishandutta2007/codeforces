#include <cstdio>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

namespace std {
    template<typename T, typename K>
    using ordered_set = tree<T, K, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
}

std::ordered_set<std::pair<int, int>, int> S[11];
int war[11];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= K; i++)
        S[i].insert({{-1, -1}, 0});
    for (int i = 1; i <= N; i++) {
        int mniejsze = 1337133713;
        int wieksze = 0;
        for (int w = 1; w <= K; w++) {
            scanf("%d", &war[w]);
            auto lower = (--S[w].lower_bound({war[w], war[w]}))->first;
            int order = S[w].order_of_key(lower);
            mniejsze = std::min(mniejsze, order - (lower.second > war[w]));
            wieksze = std::max(wieksze, order + 1);
        }
//        printf("Mniejsze: %d, wieksze: %d\n", mniejsze, wieksze);
        for (int w = 1; w <= K; w++) {
//            printf("%d:\n", w);
            int pocz = war[w], kon = war[w], ile = 1;
            auto it = S[w].find_by_order(mniejsze + 1);
            for (int z = 1; z < wieksze - mniejsze; z++) {
//                printf("Wywalam przedzial %d-%d (%d)\n", it->first.first, it->first.second, it->second);
                pocz = std::min(pocz, it->first.first);
                kon = std::max(kon, it->first.second);
                ile += it->second;
                it = S[w].erase(it);
            }
            S[w].insert({{pocz, kon}, ile});
//            printf("Dorzucam %d-%d (%d)\n", pocz, kon, ile);
        }
        printf("%d\n", S[1].rbegin()->second);
    }
    return 0;
}