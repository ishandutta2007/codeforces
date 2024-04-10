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
        ll n;
        cin >> n;
        int numtwo = 0;
        int numthree = 0;
        while (n % 2 == 0) {
            n /= 2;
            numtwo++;
        }
        while (n % 3 == 0) {
            n /= 3;
            numthree++;
        }
        if (numtwo > numthree || n != 1) {
            cout << -1 << endl;
        } else {
            cout << numthree-numtwo+numthree << endl;
        }
    }
}