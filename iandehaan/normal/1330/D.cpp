#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll d, m;

ll dp(ll starting) {
    if (starting > d) return 0;
    ll nextneeded = starting << 1;
    if (nextneeded > d) return (d-starting+1)%m;

    ll out = (nextneeded-starting) + (dp(nextneeded)*(nextneeded-starting+1))%m;
    //cout << starting << " returning " << out << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        cin >> d >> m;
        ll out = 0;
        ll mask = 1;
        cout << dp(1)%m << endl;
    }
}