#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5 + 1);

vector <int> Divisors;

vector <vector <int>> Groups;

int Val[MAX_VALUES];

int Primes[MAX_VALUES];

multiset <int> Values;

int nbValues, nbQueries;

void AddDiv(int d) {
    Divisors.push_back(d);
    vector <int> nv;
    for (int i = 0; i < d; i ++)
    {
        int sum = 0;
        for (int j = i; j < nbValues; j += d)
        {
            sum += Val[j];
        }
        nv.push_back(sum);
        Values.insert(sum * d);
    }
    Groups.push_back(nv);
    return;
}

void Init() {
    for (int p = 2; p < MAX_VALUES; p ++)
    {
        Primes[p] = 1;
    }
    for (int p = 2; p < MAX_VALUES; p ++)
    {
        if (Primes[p])
        {
            for (int j = 2 * p; j < MAX_VALUES; j += p)
                Primes[j] = 0;
        }
    }
    return;
}

void Read() {
    scanf("%lld %lld", &nbValues, &nbQueries);
    int sum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        sum += Val[i];
    }
    Divisors.clear();
    Groups.clear();
    Values.clear();
    for (int d = 2; d <= nbValues; d ++)
    {
        if (Primes[d] && !(nbValues % d))
            AddDiv(nbValues / d);
    }
    printf("%lld\n", *(-- Values.end()));
    for (int i = 0; i < nbQueries; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        int diff = b - Val[-- a];
        Val[a] = b;
        for (int j = 0; j < (int)Divisors.size(); j ++)
        {
            int d = Divisors[j];
            int id = a % d;
            Values.erase(Values.find(Groups[j][id] * d));
            Groups[j][id] += diff;
            Values.insert(Groups[j][id] * d);
        }
        printf("%lld\n", *(-- Values.end()));
    }
    return;
}

signed main() {
    Init();
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}