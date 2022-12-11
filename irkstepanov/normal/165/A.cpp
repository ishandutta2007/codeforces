#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int x[250], y[250];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = 0, d = 0, u = 0;
        for (int j = 0; j < n; j++)
        {
            if (x[j] == x[i] && y[j] < y[i]) d = 1;
            if (x[j] == x[i] && y[j] > y[i]) u = 1;
            if (y[j] == y[i] && x[i] > x[j]) r = 1;
            if (y[j] == y[i] && x[i] < x[j]) l = 1;
        }
        if (l && r && d && u) ++ans;
    }

    cout << ans;

}