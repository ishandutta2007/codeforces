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
    int nb = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        nb += Val[i] != 0;
    }
    if (nb & 1)
    {
        printf("-1\n");
        return;
    }
    Seg.clear();
    for (int i = 0; i < nbValues; i ++)
    {
        if (!Val[i])
            Seg.push_back({i, i});
        else
        {
            int next = i + 1;
            while (next < nbValues && !Val[next])
                next ++;
            if (next == i + 1)
            {
                if (Val[i] == Val[next])
                    Seg.push_back({i, next});
                else
                {
                    Seg.push_back({i, i});
                    Seg.push_back({next, next});
                }
            }
            else
            {
                if (Val[i] == Val[next])
                {
                    Seg.push_back({i, next - 2});
                    Seg.push_back({next - 1, next});
                }
                else
                {
                    Seg.push_back({i, next - 1});
                    Seg.push_back({next, next});
                }
            }
            i = next;
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