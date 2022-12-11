#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //for (int n = 950; n <= 1000; n += 4) {
    int n;
    cin >> n;
        set<pii> setik;
        int x = n / 4;
        if (n == 15) {
            --x;
        }
        for (int j = 0; j < x; ++j) {
            setik.insert({j, 0});
            setik.insert({j, 1});
        }
        int lf = 0, rg = x - 1;
        int y = 1;
        while (true) {
            vector<pii> vct = {{lf, y + 3}, {lf, y + 4}, {lf - 1, y + 3}, {lf - 1, y + 4}, {rg, y + 3}, {rg, y + 4}, {rg + 1, y + 3}, {rg + 1, y + 4}};
            int cnt = 0;
            for (int i = 0; i < sz(vct); ++i) {
                if (sz(setik) == n) {
                    break;
                }
                ++cnt;
                setik.insert(vct[i]);
            }
            if (cnt != 8) break;
            

            
            --lf, ++rg;
            y += 4;
        }
        x = 0;
        while (sz(setik) < n) {
            setik.insert({0, x});
            ++x;
        }
        for (auto p : setik) {
            cout << p.first << " " << p.second << "\n";
        }
        return 0;
        assert(sz(setik) <= n);
        map<pii, int> mapa;
        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        queue<pii> q;
        for (auto p : setik) {
            q.push(p);
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 8; ++k) {
                int xx = x + dx[k], yy = y + dy[k];
                if (!setik.count({xx, yy})) {
                    ++mapa[{xx, yy}];
                    if (mapa[{xx, yy}] == 4) {
                        q.push({xx, yy});
                        setik.insert({xx, yy});
                    }
                }
            }
        }
        //cout << n << " " << sz(setik) << endl;
        assert(sz(setik) >= (n * n / 10));
    //}

    

}