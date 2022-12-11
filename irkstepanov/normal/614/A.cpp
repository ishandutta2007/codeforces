#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("correct.txt");

    ll l, r, k;
    cin >> l >> r >> k;
    vector<ll> ans;

    ll curr = 1;
    if (curr >= l && curr <= r) {
        ans.pb(curr);
    }
    while (curr <= r / k + 1) {
        curr *= k;
        if (curr >= l && curr <= r) {
            ans.pb(curr);
        }
    }

    if (ans.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i] << " ";
        }
    }

}