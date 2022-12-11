#include <iostream>

using namespace std;

int main()
{

    long long ans[1200];
    int n, i, j;
    int p[1200];

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> p[i];

    ans[1] = 2;
    for (i = 2; i <= n; i++)
        if (p[i] == i) ans[i] = 2;
        else
        {
            ans[i] = 2;
            for (j = p[i]; j < i; j++)
                ans[i] += ans[j], ans[i] %= 1000000007;
        }

    long long otv = 0;
    for (i = 1; i <= n; i++)
        otv += ans[i], otv %= 1000000007;

    cout << otv;

}