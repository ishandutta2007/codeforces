#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    vector<int> m(n);

    forn(i, n) {
        int x;
        cin >> x;
        m[x - 1] = i;
    }

    ll ans = 0;
    forn(i, n - 1) {
         ans += static_cast<ll>(abs(m[i] - m[i + 1]));
    }

    cout << ans << "\n";

}