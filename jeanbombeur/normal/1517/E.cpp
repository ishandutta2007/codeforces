#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//   <|_|>

const int MOD = (998244353);
const int MAX_CASES = (200 * 1000);

int Val[MAX_CASES];

int nbCases;

int Count(int gauche, int droite, int delta) {
    int ans = 0;
    int curDelta = delta;
    int curZone = gauche;
    for (int i = gauche; i < droite; i ++)
    {
        curDelta += Val[i];
    }
    while (curZone + 2 <= droite && (curDelta - 2 * Val[curZone]) > 0)
    {
        curDelta -= 2 * Val[curZone];
        curZone += 2;
    }
    if (curDelta > 0)
    {
        ans += 1 + max(0LL, (curZone - gauche - 2) / 2);
    }
    //printf("%lld ", ans);
    for (int i = gauche + 2; i <= droite; i += 2)
    {
        curDelta -= 2 * Val[i - 1];
        while (curDelta <= 0 && curZone >= i)
        {
            curZone -= 2;
            curDelta += 2 * Val[curZone];
        }
        if (curZone < i)
        {
            i = droite + 1;
        }
        else if (curDelta > 0)
        {
            ans += 1 + max(0LL, (curZone - i - 2) / 2);
        }
    }
    //printf("%lld ", ans);
    curDelta = delta;
    curZone = gauche + 1;
    for (int i = gauche; i < droite; i ++)
    {
        curDelta += Val[i];
    }
    while (curZone + 2 <= droite && (curDelta - 2 * Val[curZone]) > 0)
    {
        curDelta -= 2 * Val[curZone];
        curZone += 2;
    }
    for (int i = gauche + 1; i <= droite; i += 2)
    {
        curDelta -= 2 * Val[i - 1];
        while (curDelta <= 0 && curZone >= i)
        {
            curZone -= 2;
            curDelta += 2 * Val[curZone];
        }
        if (curZone < i)
        {
            i = droite + 1;
        }
        else if (curDelta > 0)
        {
            ans += 1 + max(0LL, (curZone - i - 2) / 2);
        }
    }
    //printf("%lld\n", ans);
    return ans % MOD;
}

void Read() {
    scanf("%lld", &nbCases);
    for (int i = 0; i < nbCases; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    int answer = -1;
    int diff = 0;
    for (int i = 0; i < nbCases; i ++)
    {
        diff += Val[i];
    }
    for (int i = nbCases - 1; i >= 0; i --)
    {
        diff -= 2 * Val[i];
        if (diff > 0 && i == nbCases - 1)
            answer --;
        if (diff > 0 && i == 1)
            answer --;
        if (diff > 0 && i < nbCases - 1 && i > 1)
            answer ++;
    }
    answer += Count(0, nbCases, 0);
    answer += Count(1, nbCases, Val[0]);
    answer += Count(0, nbCases - 1, - Val[nbCases - 1]);
    answer += Count(1, nbCases - 1, Val[0] - Val[nbCases - 1]);
    //printf("%lld %lld %lld %lld\n", Count(0, nbCases, 0), Count(1, nbCases, Val[0]), Count(0, nbCases - 1, - Val[nbCases - 1]), Count(1, nbCases - 1, Val[0] - Val[nbCases - 1]));
    printf("%lld\n", answer % MOD);
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}