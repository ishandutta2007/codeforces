#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll ask(string s) {
    cout << "? " << s << endl;
    ll x;
    cin >> x;
    return x;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> tracks(m);
    for(int i = 0; i < m; i++) {
        cout << "? ";
        for(int j = 0; j < m; j++) {
            if(i == j) cout << '1';
            else cout << '0';
        }
        cout << endl;
        cin >> tracks[i].first;
        tracks[i].second = i;
    }
    sort(tracks.rbegin(), tracks.rend());
    ll minLength = -1, currLength = -1;
    string s(m, '1');
    ll ans = 0;
    minLength = ask(s);
    for(int i = 0; i < m-1; i++) {
        s[tracks[i].second] = '0';
        currLength = ask(s);
        if(minLength - currLength == tracks[i].first) ans += tracks[i].first;
        minLength = currLength;
    }
    ans += tracks[m-1].first;
    cout << "! " << ans << endl;
}