#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    int n, k;
    cin >> n >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (n == 4 || k <= n) {
        cout << "-1\n";
        return 0;
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c && i != d) {
            v.pb(i);
        }
    }
    cout << a << " " << c << " ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << d << " " << b << "\n";
    cout << c << " " << a << " ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << b << " " << d << "\n";

}