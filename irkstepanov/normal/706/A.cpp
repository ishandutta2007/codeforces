#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<int, ll> data;

const ld inf = 1e18;
const ld eps = 1e-9;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ld a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    ld ans = inf;
    while (n--) {
        ld x, y, v;
        cin >> x >> y >> v;
        ld val = sqrt((a - x) * (a - x) + (b - y) * (b - y)) / v;
        if (lt(val, ans)) {
            ans = val;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}