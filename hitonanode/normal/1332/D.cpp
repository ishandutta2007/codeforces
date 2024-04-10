#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin >> K;
    vector<vector<int>> ret{
        {(1 << 18) - 1, (1 << 17) + K, 1 << 17},
        {1 << 17, K, 1 << 17},
        {1 << 17, (1 << 17) + K, K}
    };
    printf("%d %d\n", int(ret.size()), int(ret[0].size()));
    for (auto vec : ret) {
        for (auto x : vec) printf("%d ", x);
        puts("");
    }
}