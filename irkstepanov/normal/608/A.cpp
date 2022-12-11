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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");

    int n, s;
    cin >> n >> s;
    vector<int> m(s + 1, -1);

    forn(i, n) {
        int f, t;
        cin >> f >> t;
        m[f] = max(m[f], t);
    }

    int ans = -1;
    for (int i = s; i; --i) {
        ++ans;
        ans = max(ans, m[i]);
    }
    cout << ans + 1 << "\n";

}