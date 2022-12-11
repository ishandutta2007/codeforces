// MIPT Shock Content (place 19)

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int h, m, s;
    cin >> h >> m >> s;

    int t1, t2;
    cin >> t1 >> t2;
    if (t1 == 12) {
        t1 = 0;
    }
    if (t2 == 12) {
        t2 = 0;
    }
    if (h == 12) {
        h = 0;
    }

    h *= 5, t1 *= 5, t2 *= 5;

    if (t1 > t2) {
        swap(t1, t2);
    }

    bool ok1 = true;

    if (m > 0 || s > 0) {
        if (h >= t1 && h < t2) {
            ok1 = false;
        }
    } else {
        if (h > t1 && h < t2) {
            ok1 = false;
        }
    }

    if (s > 0) {
        if (m >= t1 && m < t2) {
            ok1 = false;
        }
    } else {
        if (m > t1 && m < t2) {
            ok1 = false;
        }
    }

    if (s > t1 && s < t2) {
        ok1 = false;
    }

    bool ok2 = true;

    if (m > 0 || s > 0) {
        if (!(h >= t1 && h < t2)) {
            ok2 = false;
        }
    } else {
        if (!(h > t1 && h < t2)) {
            ok2 = false;
        }
    }

    if (s > 0) {
        if (!(m >= t1 && m < t2)) {
            ok2 = false;
        }
    } else {
        if (!(m > t1 && m < t2)) {
            ok2 = false;
        }
    }

    if (!(s > t1 && s < t2)) {
        ok2 = false;
    }

    cout << ((ok1 || ok2) ? "YES\n" : "NO\n");

}