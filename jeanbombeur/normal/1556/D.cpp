#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues, target;

int Query(int a, int b) {
    a ++, b ++;
    int ans = 0;
    printf("or %lld %lld", a, b);
    cout << endl;
    scanf("%lld", &ans);
    printf("and %lld %lld", a, b);
    cout << endl;
    int r;
    scanf("%lld", &r);
    return ans + r;
}

void Solve() {
    scanf("%lld %lld", &nbValues, &target);
    int a = Query(0, 1), b = Query(1, 2), c = Query(2, 0);
    Val[0] = (a + c - b) / 2;
    Val[1] = a - Val[0];
    Val[2] = c - Val[0];
    for (int i = 3; i < nbValues; i ++)
    {
        Val[i] = Query(0, i) - Val[0];
    }
    sort(Val, Val + nbValues);
    printf("finish %lld", Val[-- target]);
    cout << endl;
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}