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

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        k--;
        ll numgaps = (k/(n-1));
        ll num = n*numgaps;
        num += k%(n-1);
        num++;
        cout << num << endl;
    }
}