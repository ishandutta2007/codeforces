#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

char Val[2][MAX_VALUES];

vector <pair <int, int>> Moves;

int nbValues;

void Read() {
    scanf("%lld %s %s", &nbValues, Val[0], Val[1]);
    int same = 1;
    int flip = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        if (Val[0][i] != Val[1][i])
            same = 0;
        if (Val[0][i] == Val[1][i])
            flip = 0;
    }
    if (!flip && !same)
    {
        printf("NO\n");
        return;
    }
    Moves.clear();
    int nb = flip;
    for (int i = 0; i < nbValues; i ++)
    {
        if (Val[0][i] == '0')
            continue;
        int next = i + 1;
        while (next < nbValues && Val[0][next] == '1')
            next ++;
        Moves.push_back({i, next - 1});
        i = next - 1;
        nb ^= 1;
    }
    if (nb)
    {
        Moves.push_back({0, 0});
        Moves.push_back({1, nbValues - 1});
        Moves.push_back({0, nbValues - 1});
    }
    printf("YES\n");
    printf("%lld\n", (int)Moves.size());
    for (pair <int, int> a : Moves)
    {
        printf("%lld %lld\n", ++ a.first, ++ a.second);
    }
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