#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

std::map<int, int> bylo;

int calcGrundy(int mask) {
    if (bylo.count(mask) == 1)
        return bylo[mask];
    std::vector<int> ter;
    int maxBit = 29;
    for (int i = 1; i <= maxBit; i++)
        if ((1 << (i - 1)) <= mask)
            ter.push_back(calcGrundy((mask & ((1 << (i - 1)) - 1)) | (mask >> i)));
    std::sort(ter.begin(), ter.end());
    if (ter[0] != 0)  {
        bylo[mask] = 0;
        return 0;
    }
    for (int i = 1; i < ter.size(); i++) {
        if (ter[i] == ter[i - 1])
            continue;
        if (ter[i] != ter[i - 1] + 1) {
            bylo[mask] = ter[i - 1] + 1;
            return ter[i - 1] + 1;
        }
    }
    bylo[mask] = ter.back() + 1;
    return ter.back() + 1;
}

std::map<int, int> masks;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int a;
        scanf("%d", &a);
        int sq = int(std::ceil(std::sqrt(a)));
        for (int i = 2; i <= sq; i++) {
            int ile = 0;
            while (a % i == 0) {
                ile++;
                a /= i;
            }
            if (ile != 0)
                masks[i] |= (1 << (ile - 1));
        }
        if (a != 1)
            masks[a] |= 1;
    }
    int wyn = 0;
    bylo[0] = 0;
    for (auto it : masks)
        wyn ^=  calcGrundy(it.second);
    printf(wyn == 0 ? "Arpa" : "Mojtaba");
    return 0;
}