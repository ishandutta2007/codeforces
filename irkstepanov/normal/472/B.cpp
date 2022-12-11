#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;

const int N = 1000 * 1000 + 100;

int main()
{

    int n, k;
    cin >> n >> k;

    int f[3000];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    sort(f, f + n);
    int ans = 0;

    int r = n - 1;
    while (r >= 0)
    {
        ans += 2 * (f[r] - 1);
        r -= k;
    }

    cout << ans << "\n";
    return 0;

}