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

    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll curramt = 1;
    ll currind = 0;
    for (int i = 0; i < m; i++) {
        while (curramt <= b[i]) {
            if (currind >= n || curramt + a[currind] > b[i]) {
                cout << currind+1 << ' ' << b[i]-curramt+1 << endl;
                break;
            } else {
                curramt += a[currind];
                currind++;
            }
        }
        //cout << "here" << endl;
    }
}