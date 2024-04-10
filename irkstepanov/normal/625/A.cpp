#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    ios::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    if (a <= b - c) {
        cout << n / a << "\n";
        return 0;
    }

    ll ans = 0;
    if (n >= b) {
        ans = (n - b) / (b - c) + 1;
        n -= (b - c) * ans;
    }

    ans += n / a;
    cout << ans << "\n";

}