#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  Spared no expense

const int MAX_LETTERS = (5e3);

struct suff {
    int id;
};

char Text[MAX_LETTERS];

suff Suffix[MAX_LETTERS];
int Rev[MAX_LETTERS];
int Lcp[MAX_LETTERS];

int DP[MAX_LETTERS];

int nbLetters;

bool operator<(suff a, suff b) {
    for (int i = 0; i < nbLetters; i ++)
    {
        if (i + b.id >= nbLetters)
            return false;
        if (i + a.id >= nbLetters)
            return true;
        if (Text[i + a.id] != Text[i + b.id])
            return Text[i + a.id] < Text[i + b.id];
    }
    return false;
}

void Solve() {
    scanf("%lld %s", &nbLetters, Text);
    fill_n(DP, nbLetters, 0);
    fill_n(Lcp, nbLetters, 0);
    for (int i = 0; i < nbLetters; i ++)
    {
        Suffix[i] = {i};
    }
    sort(Suffix, Suffix + nbLetters);
    for (int i = 0; i < nbLetters; i ++)
    {
        Rev[Suffix[i].id] = i;
    }
    for (int i = 0; i < nbLetters - 1; i ++)
    {
        for (int j = 0; j < nbLetters; j ++)
        {
            if (max(Suffix[i].id, Suffix[i + 1].id) + j >= nbLetters)
                break;
            if (Text[Suffix[i].id + j] != Text[Suffix[i + 1].id + j])
                break;
            Lcp[i] ++;
        }
    }
    int ans = 0;
    for (int i = nbLetters - 1; i >= 0; i --)
    {
        int cur = Rev[i];
        int lcp = Lcp[cur];
        for (int j = cur + 1; j < nbLetters; j ++)
        {
            if (Suffix[j].id > i)
                DP[i] = max(DP[i], DP[Suffix[j].id] - lcp);
            lcp = min(lcp, Lcp[j]);
        }
        DP[i] += nbLetters - i;
        ans = max(ans, DP[i]);
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}