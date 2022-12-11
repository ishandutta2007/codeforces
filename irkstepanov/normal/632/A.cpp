#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{
    
    ll n, p;
    cin >> n >> p;
    
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    ll x = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == "halfplus") {
            ans += (ll)(p * x + p / 2);
            x = 2 * x + 1;
        } else {
            ans += p * x;
            x *= 2;
        }
    }
    
    cout << ans << "\n";
    
}