#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm back

const int MAX_VALUES = 2e5;

pair <int, int> Val[MAX_VALUES];

int Taken[MAX_VALUES];

int nbVertices, nbEdges;

int Ask() {
    printf("? ");
    for (int i = 0; i < nbEdges; i ++)
    {
        printf("%c", Taken[i] ? '1' : '0');
    }
    cout << endl;
    int ans;
    scanf("%lld", &ans);
    return ans;
}

void Solve() {
    scanf("%lld %lld", &nbVertices, &nbEdges);
    for (int i = 0; i < nbEdges; i ++)
    {
        Taken[i] = 1;
        Val[i] = {Ask(), i};
        Taken[i] = 0;
    }
    sort(Val, Val + nbEdges);
    int ans = 0;
    for (int i = 0; i < nbEdges; i ++)
    {
        Taken[Val[i].second] = 1;
        if (Ask() < ans + Val[i].first)
            Taken[Val[i].second] = 0;
        else
            ans += Val[i].first;
    }
    printf("! %lld", ans);
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