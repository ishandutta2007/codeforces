#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    set<int> ret;
    ret.insert(0);
    for (int i = 1; i * i <= N; i++)
    {
        ret.insert(i);
        ret.insert(N / i);
    }
    printf("%d\n", (int)ret.size());
    for (auto x : ret) printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}