#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    int t1, t2, t3;
    cin >> x >> y >> z;
    cin >> t1 >> t2 >> t3;

    int ladder = t1 * abs(x - y);

    int elevator = t2 * abs(z - x) + t2 * abs(y - x) + 3 * t3;
    //cout << elevator << endl;

    cout << (elevator <= ladder ? "YES\n" : "NO\n");
    
}