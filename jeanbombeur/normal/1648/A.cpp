#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (2e5);

map <int, int> Colors;
int cnt = 1;

vector <int> Spots[MAX_VALUES][2];

int nbLines, nbColumns;

int Sum(vector <int> &acc) {
    int sum = 0;
    int sz = acc.size();
    for (int i = 1; i < sz; i ++)
    {
        sum += i * (sz - i) * (acc[i] - acc[i - 1]);
    }
    return sum;
}

void Solve() {
    scanf("%lld %lld", &nbLines, &nbColumns);
    for (int i = 0; i < nbLines; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            int c;
            scanf("%lld", &c);
            if (!Colors[c])
                Colors[c] = cnt ++;
            Spots[Colors[c]][0].push_back(i);
            Spots[Colors[c]][1].push_back(j);
        }
    }
    for (int i = 1; i < cnt; i ++)
    {
        sort(Spots[i][1].begin(), Spots[i][1].end());
    }
    int ans = 0;
    for (int i = 1; i < cnt; i ++)
    {
        ans += Sum(Spots[i][0]);
        ans += Sum(Spots[i][1]);
    }
    printf("%lld\n", ans);
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