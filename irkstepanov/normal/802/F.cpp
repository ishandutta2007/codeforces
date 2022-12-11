#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 250;

int main()
{

    //ifstream cin("./python/input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        ll sum = 0, sum2 = 0;
        ll maxx = 0;
        vector<ll> a;
        for (int i = 0; i < nmax; ++i) {
            ll x;
            cin >> x;
            a.pb(x);
            maxx = max(maxx, x);
            sum += x;
            sum2 += x * x;
        }
        ld mean = ld(sum) / nmax;
        ld disp = ld(sum2) / nmax - (ld(sum) / nmax) * (ld(sum) / nmax);
        ld sigma = sqrt(disp);
        if (maxx / sigma <= 1.9) {
            cout << "uniform\n";
        } else {
            cout << "poisson\n";
        }
    }

}