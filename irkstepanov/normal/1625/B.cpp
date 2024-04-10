#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, vector<int> > mapa;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mapa[a[i]].pb(i);
        }
        int ans = -1;
        for (auto it : mapa) {
            for (int i = 0; i + 1 < sz(it.second); ++i) {
                int x = it.second[i];
                int y = it.second[i + 1];
                ans = max(ans, x + 1 + (n - y - 1));
            }
        }
        cout << ans << "\n";
    }

}