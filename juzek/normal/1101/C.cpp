#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

std::vector<std::pair<int, int>> pary;
std::vector<std::pair<int, std::pair<int, int>>> wartosci;
std::set<int> terA, terB;
int kolor[1000007];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int a, b;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &a, &b);
            pary.push_back({a, b});
            wartosci.push_back({a, {1, i}});
            wartosci.push_back({b + 1, {0, i}});
        }
        std::sort(wartosci.begin(), wartosci.end());
        bool bylA = false;
        bool bylB = false;
        for (auto it : wartosci) {
            if (it.second.first == 1) {
                if (terA.size() == 0 && terB.size() == 0) {
                    if (!bylA) {
                        kolor[it.second.second] = 1;
                        terA.insert(it.second.second);
                        bylA = true;
                    } else {
                        kolor[it.second.second] = 2;
                        terB.insert(it.second.second);
                        bylB = true;
                    }
                } else if (terA.size() != 0) {
                    kolor[it.second.second] = 1;
                    terA.insert(it.second.second);
                    bylA = true;
                } else if (terB.size() != 0) {
                    kolor[it.second.second] = 2;
                    terB.insert(it.second.second);
                    bylB = true;
                }
            } else {
                if (kolor[it.second.second] == 1)
                    terA.erase(it.second.second);
                else
                    terB.erase(it.second.second);
            }
        }
        pary.clear();
        wartosci.clear();
        if (bylA && bylB) {
            for (int i = 1; i <= N; i++)
                printf("%d ", kolor[i]);
            printf("\n");
        } else {
            printf("-1\n");
        }
        for (int i = 1; i <= N; i++)
            kolor[i] = 0;
    }
    return 0;
}