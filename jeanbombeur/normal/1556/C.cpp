#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

pair <int, int> Stack[MAX_VALUES];
int fin = 0;

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int sum = 0;
    int ans = 0;
    Stack[fin ++] = {0, 0};
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (!(i & 1))
            sum += Val[i];
        else
        {
            int last = sum;
            sum -= Val[i];
            while (fin && Stack[fin - 1].first > sum)
            {
                fin --;
                ans += last - Stack[fin].first - 1;
                last = Stack[fin].first;
                ans += ((Stack[fin].second + 1) * (Stack[fin].second + 2)) / 2;
            }
            if (fin)
                ans += last - sum - 1;
            int cnt = fin > 0;
            if (fin && Stack[fin - 1].first == sum)
                cnt += Stack[-- fin].second;
            Stack[fin ++] = {sum, cnt};
        }
    }
    while (fin)
    {
        fin --;
        ans += (Stack[fin].second * (Stack[fin].second + 1)) / 2;
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