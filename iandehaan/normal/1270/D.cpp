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

    ll n, k;
    cin >> n >> k;
    map<ll, ll> cnts;
    for (int i = 0; i <= k; i++) {
        cout << "? ";
        for (int j = 0; j <= k; j++) {
            if (j != i) cout << j+1 << ' ';
        }
        cout << endl;
        int pos, apos;
        cin >> pos >> apos;
        if (cnts.find(apos) == cnts.end()) cnts[apos] = 0;
        cnts[apos]++;
    }

    ll biggestel = -1;
    for (pii thing : cnts) biggestel = max(biggestel, thing.first);
    cout << "! " << cnts[biggestel] << endl;

}