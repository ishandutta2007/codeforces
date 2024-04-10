#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;

    int x = 0, y = n - 1;
    while (x != n)
    {
        if (x >= a && y <= b) ++ans;
        ++x, --y;
    }

    cout << ans;

}