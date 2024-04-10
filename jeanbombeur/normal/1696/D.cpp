#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (3e5);

int Val[MAX_VALUES];

int Pref[MAX_VALUES][2];
int Suff[MAX_VALUES][2];

int nbValues;

int Dist(int left, int right, int step) {
    if (left == right)
        return 0;
    if (!left)
        return 1 + Dist(left, Pref[right][step], step ^ 1);
    return 1 + Dist(Suff[left][step], right, step ^ 1);
}

void Read() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i)
        {
            Pref[i][0] = Val[i] < Val[Pref[i - 1][0]] ? i : Pref[i - 1][0];
            Pref[i][1] = Val[i] > Val[Pref[i - 1][1]] ? i : Pref[i - 1][1];
        }
    }
    Suff[nbValues - 1][0] = Suff[nbValues - 1][1] = nbValues - 1;
    for (int i = nbValues - 2; i >= 0; i --)
    {
        Suff[i][0] = Val[i] < Val[Suff[i + 1][0]] ? i : Suff[i + 1][0];
        Suff[i][1] = Val[i] > Val[Suff[i + 1][1]] ? i : Suff[i + 1][1];
    }
    if (nbValues == 1)
    {
        printf("0\n");
        return;
    }
    if (!Pref[nbValues - 1][0] || Pref[nbValues - 1][0] == nbValues - 1)
    {
        if (!Pref[nbValues - 1][1] || Pref[nbValues - 1][1] == nbValues - 1)
        {
            printf("1\n");
            return;
        }
        printf("%lld\n", Dist(0, Pref[nbValues - 1][1], 0) + Dist(Pref[nbValues - 1][1], nbValues - 1, 0));
        return;
    }
    printf("%lld\n", Dist(0, Pref[nbValues - 1][0], 1) + Dist(Pref[nbValues - 1][0], nbValues - 1, 1));
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}