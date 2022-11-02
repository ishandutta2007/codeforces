#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

std::map<std::string, int> ludzie;
std::vector<int> v[47];
std::vector<std::pair<int, int>> kr;
int moge[1000007];
int mogeCzl[47];
long long e[47];
int p[47];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int typ;
    int ter = 0;
    std::string s;
    int ile = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &typ);
        if (typ == 1)
            ter++;
        else {
            std::cin >> s;
            if (ludzie.count(s) == 0)
                ludzie[s] = ++ile;
            if (ter == 0)
                continue;
            kr.emplace_back(ludzie[s], ter);
            v[ludzie[s]].push_back(ter);
        }
    }
    int zeit = 0;
    for (int czl = 1; czl <= ile; czl++) {
        zeit++;
        for (auto it : v[czl])
            moge[it] = zeit;
        for (auto it : kr)
            if (moge[it.second] == zeit)
                mogeCzl[it.first] = zeit;
        for (int i = 1; i <= ile; i++)
            if (mogeCzl[i] != zeit) {
                e[czl - 1] |= 1LL << (i - 1);
                e[i - 1] |= 1LL << (czl - 1);
            }
    }
    srand(998244353);
    for (int i = 0; i < ile; i++)
        p[i] = i;
    long long can;
    int wyn = 0;
    for (int T = 5000; T; T--) {
        std::random_shuffle(p, p + ile);
        can = (1LL << ile) - 1;
        int ss = 0;
        for (int i = 0; i < ile; i++)
            if ((can >> p[i]) & 1)
                ss++, can &= e[p[i]];
        wyn = std::max(wyn, ss);
    }
    printf("%d", wyn);
    return 0;
}