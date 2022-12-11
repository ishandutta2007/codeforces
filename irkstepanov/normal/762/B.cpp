#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    vector<ll> x, y;
    int n;
    cin >> n;

    while (n--) {
        ll cost;
        cin >> cost;
        string s;
        cin >> s;
        if (s == "USB") {
            x.pb(cost);
        } else {
            y.pb(cost);
        }
    }

    sort(all(x));
    sort(all(y));

    int cnt = 0;
    ll sum = 0;
    vector<ll> alive;
    int i;
    for (i = 0; i < sz(x) && i < a; ++i) {
        ++cnt;
        sum += x[i];
    }
    for (; i < sz(x); ++i) {
        alive.pb(x[i]);
    }

    for (i = 0; i < sz(y) && i < b; ++i) {
        ++cnt;
        sum += y[i];
    }
    for (; i < sz(y); ++i) {
        alive.pb(y[i]);
    }

    sort(all(alive));
    for (i = 0; i < sz(alive) && i < c; ++i) {
        ++cnt;
        sum += alive[i];
    }

    cout << cnt << " " << sum << "\n";

}