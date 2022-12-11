#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())

using namespace std;

typedef long long ll;

int main()
{

    string s;
    cin >> s;

    map<char, ll> m;
    for (int i = 0; i < sz(s); ++i) {
        ++m[s[i]];
    }

    ll ans = 0;
    for (auto& it : m) {
        ans += it.second * it.second;
    }

    cout << ans << "\n";

}