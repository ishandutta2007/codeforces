#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

int main()
{

    //freopen("input.txt", "r", stdin);

    ld d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;

    ld ans = (l - d) / (v1 + v2);
    cout << fixed;
    cout.precision(10);
    cout << ans << "\n";

}