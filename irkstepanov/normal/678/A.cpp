#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ll n, k;
    cin >> n >> k;
    ll x = (n / k) * k;
    x += k;
    cout << x << "\n";

}