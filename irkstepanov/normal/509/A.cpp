#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    int a[15][15];

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        a[1][i] = 1;
    for (int i = 1; i <= n; i++)
        a[i][1] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
        a[i][j] = a[i - 1][j] + a[i][j - 1];

    cout << a[n][n] << "\n";

}