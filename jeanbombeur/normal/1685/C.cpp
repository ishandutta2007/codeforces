#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  We must be better

const int MAX_VALUES = (2e5);

char Seq[MAX_VALUES];
int Height[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld %s", &nbValues, Seq);
    nbValues *= 2;
    int first = -1;
    int last = -1;
    for (int i = 1; i <= nbValues; i ++)
    {
        Height[i] = Height[i - 1] + (Seq[i - 1] == '(' ? 1 : -1);
    }
    for (int i = 0; i <= nbValues; i ++)
    {
        if (Height[i] < 0)
            last = i;
    }
    for (int i = nbValues; i >= 0; i --)
    {
        if (Height[i] < 0)
            first = i;
    }
    if (first < 0)
    {
        printf("0\n");
        return;
    }
    int j = 0, k = first, l = nbValues;
    for (int i = 0; i < first; i ++)
    {
        if (Height[i] > Height[j])
            j = i;
    }
    for (int i = last; i <= nbValues; i ++)
    {
        if (Height[i] > Height[l])
            l = i;
    }
    for (int i = first; i < last; i ++)
    {
        if (Height[i] > Height[k])
            k = i;
    }
    if (Height[j] + Height[l] >= Height[k])
        printf("1\n%lld %lld\n", j + 1, l);
    else
        printf("2\n%lld %lld\n%lld %lld\n", j + 1, k, k + 1, l);
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