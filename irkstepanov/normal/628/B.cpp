#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int nmax = 300500;

int main()
{

    char s[nmax];
    scanf("%s", s);

    int n = 0;
    for (; s[n]; ++n) ;

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (x % 4 == 0) {
            ans += (ll)(i + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = (s[i] - '0');
        if (x % 4 == 0) {
            ++ans;
        }
    }

    cout << ans << "\n";

}