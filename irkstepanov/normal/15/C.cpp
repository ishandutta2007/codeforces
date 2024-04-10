#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

ll pref(ll m)
{
    if (m % 4 == 0) {
        return m;
    }
    if (m % 4 == 1) {
        return 1;
    }
    if (m % 4 == 2) {
        return m + 1;
    }
    if (m % 4 == 3) {
        return 0;
    }
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll sum = 0;

    while (n--) {
        ll x, m;
        cin >> x >> m;
        sum ^= (pref(x + m - 1) ^ pref(x - 1));
    }

    cout << (sum != 0 ? "tolik\n" : "bolik\n");

}