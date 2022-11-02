#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define int long long
using namespace std;

//  <|_|>

// Finally

const int MAX_VALUES = (1e5);

multiset <int> Values;

pair <int, int> Steps[MAX_VALUES * 100];
int nbSteps = 0;

int nbValues;

void Solve(int nb, int mult) {
    if (nb <= 2)
        return;
    int p = nb;
    while (p & (p - 1))
        p &= p - 1;
    if (p == nb)
    {
        Solve(nb - 1, mult);
        return;
    }
    for (int d = 1; d <= nb - p; d ++)
    {
        int a = (p + d) * mult;
        int b = (p - d) * mult;
        Steps[nbSteps ++] = {a, b};
        Values.erase(Values.find(a));
        Values.erase(Values.find(b));
        Values.insert(a + b);
        Values.insert(a - b);
    }
    Solve(2 * p - nb - 1, mult);
    Solve(nb - p, mult << 1);
    return;
}

void Read() {
    scanf("%lld", &nbValues);
    if (nbValues == 2)
    {
        printf("-1\n");
        return;
    }
    nbSteps = 0;
    Values.clear();
    for (int i = 1; i <= nbValues; i ++)
    {
        Values.insert(i);
    }
    int p = nbValues;
    while (p & (p - 1))
        p &= p - 1;
    if (p == nbValues)
        p >>= 1;
    Solve(nbValues, 1);
    if (nbValues == 5)
        p = 2;
    Steps[nbSteps ++] = {p, p};
    Values.erase(Values.find(p));
    Values.erase(Values.find(p));
    p <<= 1;
    Values.insert(p);
    if (nbValues == 5)
        p = 8;
    while (*Values.begin() < p)
    {
        int a = *Values.begin();
        Values.erase(Values.begin());
        Steps[nbSteps ++] = {0, a};
        Steps[nbSteps ++] = {a, a};
        Values.insert(a << 1);
    }
    Steps[nbSteps ++] = {0, p};
    printf("%lld\n", nbSteps);
    for (int i = 0; i < nbSteps; i ++)
    {
        printf("%lld %lld\n", Steps[i].first, Steps[i].second);
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