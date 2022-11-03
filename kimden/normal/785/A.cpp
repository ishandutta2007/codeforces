#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    map<string, int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    string s;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> s;
        ans += mp[s];
    }
    cout << ans << endl;

    return 0;
}