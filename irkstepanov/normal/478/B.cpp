#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;
const int inf = 1000000000;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll n, m;
    cin >> n >> m;

    ll ans1 = (n - m + 1) * (n - m) / 2;

    ll a = n / m;
    ll s = a * m + m - n;
    ll ans2 = a * (a - 1) / 2 * s;
    ans2 += (a + 1) * a / 2 * (m - s);

    cout << ans2 << " " << ans1 << "\n";

}