#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    int n, m;
    cin >> n >> m;
    int a[120];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tek = a[0];
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (tek + a[i] <= m)
        {
            tek += a[i];
        }
        else
        {
            tek = a[i];
            ++ans;
        }
    }

    cout << ans;

}