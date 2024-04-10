#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<int, ll> data;

const int ops = 300;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    ld l, v1, v2;
    cin >> n >> l >> v1 >> v2 >> k;

    ld lf = l / v2, rg = l / v1;
    for (int step = 0; step < ops; ++step) {
        ld md = (lf + rg) / 2;
        ld x = (l - v1 * md) / (v2 - v1);
        ld men = 0;
        int rest = n;
        ld spent = 0;
        while (rest) {
            rest = max(rest - k, 0);
            spent += x;
            if (rest) {
                ld t = (x * v2 - x * v1) / (v1 + v2);
                men += v1 * t + v1 * x;
                spent += t;
            }
        }
        if (spent <= md) {
            rg = md;
        } else {
            lf = md;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << rg << '\n';

}