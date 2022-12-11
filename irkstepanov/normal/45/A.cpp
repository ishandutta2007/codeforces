#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string s;
    cin >> s;
    int pos;
    for (int i = 0; i < 12; ++i) {
        if (a[i] == s) {
            pos = i;
        }
    }
    int k;
    cin >> k;

    pos = (pos + k) % 12;
    cout << a[pos] << "\n";

}