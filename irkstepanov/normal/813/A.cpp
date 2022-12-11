#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll a = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a += x;
    }

    int q;
    cin >> q;

    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (a <= r) {
            cout << max(a, l) << "\n";
            return 0;
        }
    }

    cout << "-1\n";

}