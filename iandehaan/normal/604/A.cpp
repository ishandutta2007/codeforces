#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m[5];
    for (ll i = 0; i < 5; i++) cin >> m[i];
    ll w[5];
    for (ll i = 0; i < 5; i++) cin >> w[i];

    ll hs, hu;
    cin >> hs >> hu;
    ll score = 0;
    ll amt = 500;
    for (ll i = 0; i < 5; i++) {
        score += round(max(0.3*amt, ((1-(m[i]/250.0))*amt - 50*w[i])));
        amt += 500;
        //cout << i << ' ' << score << endl;
    }
    score += 100*hs;
    score -= 50*hu;
    cout << score << endl;
}