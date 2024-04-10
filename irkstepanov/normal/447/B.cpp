/**by Stepanov Ilia**/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    string s;
    int w[30], k;

    cin >> s >> k;
    for (int i = 0; i < 26; i++)
        cin >> w[i];

    ll ans = 0;
    for (int i = 1; i <= s.size(); i++)
        ans += (ll) (w[s[i - 1] - 'a'] * i);

    int wmax = 0;
    for (int i = 0; i < 26; i++)
        wmax = max(w[i], wmax);

    for (int i = 1; i <= k; i++)
        ans += (ll) (wmax * (i + s.size()));

    cout << ans;

}