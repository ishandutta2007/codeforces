#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> type;

int main()
{

    //ifstream cin("input.txt");

    ll n, d;
    cin >> n >> d;

    ll prev = 0, a;
    ll ans = 0;

    while (n--) {
        cin >> a;
        if (a <= prev) {
            ll k = (prev - a) / d + 1;
            ans += k;
            a += k * d;
        }
        prev = a;
    }

    cout << ans << "\n";

}