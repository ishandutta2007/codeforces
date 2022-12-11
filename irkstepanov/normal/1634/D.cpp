#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int get(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    int ans;
    cin >> ans;
    return ans;
}

const int inf = 1e9;

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
        vector<int> vct;
        int val;
        for (int i = 3; i <= n; ++i) {
            int x = get(1, 2, i);
            if (i == 3 || val == x) {
                val = x;
                vct.pb(i);
            } else if (x > val) {
                val = x;
                vct = {i};
            }
        }
        /*if (sz(vct) == n - 2) {
            cout << "! 1 2" << endl;
            continue;
        }*/
        bool poss = false;
        if (sz(vct) == n - 2) {
            poss = true;
        }
        while (sz(vct) >= 2) {
            vct.pop_back();
        }
        vector<int> total;
        for (int i = 1; i <= n; ++i) {
            if (i != vct[0]) {
                total.pb(i);
            }
        }
        int maxx = -inf;
        vector<pii> p;
        for (int i = 0; i < sz(total); ++i) {
            int x = get(total[i], total[(i + 1) % sz(total)], vct[0]);
            if (x > maxx) {
                maxx = x;
                p = {{total[i], total[(i + 1) % sz(total)]}};
            } else if (x == maxx) {
                p.pb({total[i], total[(i + 1) % sz(total)]});
            }
        }
        if (maxx == val && poss) {
            cout << "! 1 2" << endl;
            continue;
        }
        if (sz(p) > 2) {
            cout << "! " << vct[0] << " " << vct[0] << endl;
            continue;
        }
        //cout << "!!! " << vct[0] << " " << p[0].first << " " << p[0].second << " " << p[1].first << " " << p[1].second << endl;
        int x = p[0].first;
        if (p[1].first != x && p[1].second != x) {
            x = p[0].second;
        }
        cout << "! " << vct[0] << " " << x << endl;
    }

}