#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int tt, k;
    cin >> tt >> k;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        if (k == 1) {
            if ((n & 1) && (m & 1)) {
                cout << "-\n";
            } else {
                cout << "+\n";
            }
            continue;
        }
        int s = min(n, m);
        if (s % (k + 1) == 0) {
            cout << "+\n";
            continue;
        }
        char c;
        if ((s / (k + 1)) & 1) {
            c = '+';
        } else {
            c = '-';
        }
        int d = n - s + m - s;
        if (d & 1) {
            if (c == '+') {
                c = '-';
            } else {
                c = '+';
            }
        }
        cout << c << "\n";
    }

}