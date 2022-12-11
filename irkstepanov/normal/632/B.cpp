#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{
    
    int n;
    cin >> n;
    vector <ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    
    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            suma += v[i];
        } else {
            sumb += v[i];
        }
    }
    
    ll ans = sumb;
    ll a = suma, b = sumb;
    for (int pref = 0; pref < n; ++pref) {
        if (s[pref] == 'A') {
            a -= v[pref];
            b += v[pref];
        } else {
            a += v[pref];
            b -= v[pref];
        }
        ans = max(ans, b);
    }
    
    a = suma, b = sumb;
    for (int suff = n - 1; suff >= 0; --suff) {
        if (s[suff] == 'A') {
            a -= v[suff];
            b += v[suff];
        } else {
            a += v[suff];
            b -= v[suff];
        }
        ans = max(ans, b);
    }
    
    cout << ans << "\n";
    
}