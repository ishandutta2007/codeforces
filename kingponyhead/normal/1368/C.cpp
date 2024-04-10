// Criminal.
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n, m, q, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector < pair < int , int > > vec;
    int xc = 0, yc = 0;
    for (int i = 0; i <= n; i ++)
    {
        int dif = (i % 2 == 0) ? (-1) : (1);
        for (int a = -1; a <= 1; a ++)
            for (int b = -1; b <= 1; b ++)
                if (a || b)
                    vec.push_back({xc + a, yc + b + dif});
        xc += 2;
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    printf("%d\n", (int)vec.size());
    for (auto X : vec)
        printf("%d %d\n", X.first, X.second);
    return 0;
}