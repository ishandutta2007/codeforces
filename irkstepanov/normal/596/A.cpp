#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define openStream(in, out) ifstream cin(in); ofstream cout(out);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    int n;
    cin >> n;
    vector<pair<int, int> > v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    bool allX = true;
    bool allY = true;
    for (int i = 1; i < n; ++i) {
        if (v[i].first != v[0].first) {
            allX = false;
        }
        if (v[i].second != v[0].second) {
            allY = false;
        }
    }

    if (allX || allY) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, abs(v[i].first - v[j].first) * abs(v[i].second - v[j].second));
        }
    }
    cout << ans << "\n";

}