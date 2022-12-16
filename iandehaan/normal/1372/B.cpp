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
        int fac = n;
        for (int i = 2; i <= sqrt(n)+3; i++) {
            if (n%i == 0) {
                fac = i;
                break;
            }
        }
        cout << n/fac << ' ' << n-(n/fac) << endl;
    }
}