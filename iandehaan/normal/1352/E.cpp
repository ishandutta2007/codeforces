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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<bool> attain(n*n+1);
        for (int i = 0; i <= n*n; i++) attain[i] = false;

        int pref[n];
        pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];

        for (int i = 0; i < n; i++) {
            if (i != 0) attain[pref[i]] = true;
            for (int j = 0; j < i-1; j++) {
                attain[pref[i]-pref[j]] = true;
            }
        }

        int out = 0;
        for (int i = 0; i < n; i++) {
            if (attain[a[i]]) out++;
        }
        cout << out << '\n';
    }
}