#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    string curr = "";
    for (int i = 0; i < n; ++i) {
        curr += "1";
    }
    cout << "? " << curr << "\n";
    cout.flush();
    int x;
    cin >> x;
    curr[0] = '0';
    cout << "? " << curr << "\n";
    cout.flush();
    int y;
    cin >> y;

    int first;

    if (x < y) {
        first = 1;
    } else {
        first = 0;
    }

    int d = 1 - first;

    for (int i = 0; i < n; ++i) {
        curr[i] = char(d + '0');
    }

    int lf = 0, rg = n;
    cout << "? " << curr << "\n";
    cout.flush();
    int pr;
    cin >> pr;

    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        string nx = curr;
        for (int i = lf; i <= md; ++i) {
            nx[i] = char(first + '0');
        }
        cout << "? " << nx << "\n";
        cout.flush();
        int val;
        cin >> val;
        if (val != pr - (md - lf + 1)) {
            rg = md;
        } else {
            lf = md;
        }
    }

    int ans[2];
    ans[first] = 0;
    ans[d] = rg;

    cout << "! " << ans[0] + 1 << " " << ans[1] + 1 << "\n";
    cout.flush();

}