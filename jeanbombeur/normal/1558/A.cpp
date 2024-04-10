#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

vector <int> Ans;

void Solve() {
    int winA, winB;
    scanf("%lld %lld", &winA, &winB);
    int sum = winA + winB;
    Ans.clear();
    for (int i = 0; i < 2; i ++)
    {
        int m1 = (sum + 1) / 2, m2 = sum / 2;
        int d1 = min(abs(m1 - winA), abs(m2 - winB));
        int d2 = min(abs(m2 - winA), abs(m1 - winB));
        for (int x = d1; x <= winA + winB - d2; x += 2)
        {
            Ans.push_back(x);
        }
        swap(winA, winB);
    }
    sort(Ans.begin(), Ans.end());
    Ans.resize(unique(Ans.begin(), Ans.end()) - Ans.begin());
    printf("%lld\n", (int)Ans.size());
    for (int x : Ans)
    {
        printf("%lld ", x);
    }
    printf("\n");
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