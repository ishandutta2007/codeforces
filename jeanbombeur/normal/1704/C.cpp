#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

vector <int> Inter;

int nbHouses, nbInfected;

void Read() {
    scanf("%lld %lld", &nbHouses, &nbInfected);
    for (int i = 0; i < nbInfected; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + nbInfected);
    Inter.clear();
    Inter.push_back(nbHouses + Val[0] - Val[nbInfected - 1]);
    for (int i = 1; i < nbInfected; i ++)
    {
        Inter.push_back(Val[i] - Val[i - 1]);
    }
    sort(Inter.begin(), Inter.end());
    reverse(Inter.begin(), Inter.end());
    int ans = 0;
    for (int i = 0; i < (int)Inter.size(); i ++)
    {
        if (Inter[i] - 4 * i - 2 > 0)
            ans += Inter[i] - 4 * i - 2;
        else if (Inter[i] - 1 - 4 * i > 0)
            ans ++;
    }
    printf("%lld\n", nbHouses - ans);
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