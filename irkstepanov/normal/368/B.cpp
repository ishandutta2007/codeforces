#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

#define pb push_back

using namespace std;

int main()
{

    int n, m;
    int a[100500];

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int met[100500], kol = 0, ans[100500];
    for (int i = 0; i < 100500; i++)
        met[i] = 0;

    for (int i = n; i >= 1; i--)
    {
        if (met[a[i]] == 0) ++kol;
        met[a[i]] = 1;
        ans[i] = kol;
    }

    while (m--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }

}