#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

vector <pair <int, int>> Seg;

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    if (nbValues & 1)
    {
        printf("-1\n");
        return;
    }
    Seg.clear();
    for (int i = 0; i < nbValues; i += 2)
    {
        if (Val[i] == Val[i + 1])
            Seg.push_back({i, i + 1});
        else
        {
            Seg.push_back({i, i});
            Seg.push_back({i + 1, i + 1});
        }
    }
    printf("%lld\n", (int)Seg.size());
    for (pair <int, int> a : Seg)
        printf("%lld %lld\n", ++ a.first, ++ a.second);
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