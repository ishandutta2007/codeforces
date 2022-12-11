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
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > v[i].second) {
            swap(v[i].first, v[i].second);
        }
    }
    sort(all(v));

    vector<int> ans;
    pii curr = v[0];

    for (int i = 0; i < n; ++i) {
        if (v[i].first > curr.second) {
            ans.pb(curr.second);
            curr = v[i];
        } else {
            curr.first = v[i].first;
            curr.second = min(curr.second, v[i].second);
        }
        if (i == n - 1) {
            ans.pb(curr.second);
        }
    }

    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}