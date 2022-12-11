#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{

    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/

    int n, i, j, ans = 0;
    int m[1005];

    cin >> n;

    for (i = 1; i <= n; i++)
    {
        int x;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            if (i == j) {m[i] = x; ans += x;}
        }
    }

    ans %= 2;

    vector <int> otv;

    int q;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1 || t == 2)
        {
            int x;
            scanf("%d", &x);
            ans = 1 - ans;
        }
        if (t == 3)
            otv.push_back(ans);
    }

    for (i = 0; i < otv.size(); i++)
        printf("%d", otv[i]);

}