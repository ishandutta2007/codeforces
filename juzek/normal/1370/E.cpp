#include <bits/stdc++.h>

using namespace std;

char s1[1000007], s2[1000007];

int main() {
    int n;
    scanf("%d", &n);
    scanf(" %s %s", s1 + 1, s2 + 1);
    int hmm = 0;
    std::set<int> pos[2];
    for (int i = 1; i <= n; i++) {
        hmm += s1[i] == '0';
        hmm -= s2[i] == '0';
        if (s1[i] != s2[i])
            pos[s1[i] == '0'].insert(i);
    }
    if (hmm) {
        printf("-1");
        return 0;
    }
    int op = 0;
    while (!pos[0].empty() || !pos[1].empty()) {
        for (auto &it : pos)
            if (it.empty())
                it.insert(1337133713);
        int kto = *pos[1].begin() < *pos[0].begin();
        int ter = 0;
        auto it = pos[kto].begin();
        while ((it = pos[kto].lower_bound(ter)) != pos[kto].end()) {
            ter = *it;
            pos[kto].erase(it);
            kto = !kto;
        }
        op++;
    }
    printf("%d\n", op);
    return 0;
}