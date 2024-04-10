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

    int n, k;
    cin >> n >> k;
    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];


    int out = 0;
    int amtalone = 2*k-n;
    for (int i = n-1; i >= max(0, n-amtalone); i--) {
        out = max(out, s[i]);
    }

    int m = n-amtalone;
    for (int i = 0; i < m; i++) {
        out = max(out, s[i] + s[m-i-1]);
    }
    cout << out << endl;
}