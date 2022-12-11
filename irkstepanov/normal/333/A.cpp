#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

ll f(ll n)
{
    if (n == 0) {
        return 0;
    }
    if (n % 3) {
        return n / 3 + 1;
    } else {
        return f(n / 3);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    ll n;
    cin >> n;

    cout << f(n) << "\n";

}