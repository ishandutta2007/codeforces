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

    int n;
    cin >> n;
    double out = 0;
    for (int i = 1; i <= n; i++) {
        out += 1.0/i;
    }
    cout << fixed << setprecision(8) << out << endl;
}