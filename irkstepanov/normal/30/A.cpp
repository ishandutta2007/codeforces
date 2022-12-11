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
typedef pair<ll, int> pll;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    if (b == 0) {
        cout << "0\n";
        return 0;
    }
    if (a == 0) {
        cout << "No solution\n";
        return 0;
    }

    if (b % a) {
        cout << "No solution\n";
        return 0;
    }

    int y = b / a;

    for (int x = -1000; x <= 1000; ++x) {
        int z = 1;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            z *= x;
            if (abs(z) > abs(y)) {
                ok = false;
                break;
            }
        }
        if (ok && z == y) {
            cout << x << "\n";
            return 0;
        }
    }

    cout << "No solution\n";

}