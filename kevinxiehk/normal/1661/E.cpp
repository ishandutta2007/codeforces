#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1000000000000000000LL
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int n;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string grid[3];
bool valid(int x, int y) {
    if(x < 0 || x >= 3) return false;
    if(y < 0 || y >= n) return false;
    if(grid[x][y] == '1') return false;
    return true;
}
int cnt = 1;
int vi[3][500005];
void solve(int TC) {
    cin >> n;
    n += 2;
    cin >> grid[0];
    cin >> grid[1];
    cin >> grid[2];
    for(int i = 0; i < 3; i++) grid[i] = '0' + grid[i] + '0';

    for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) grid[i][j] ^= 1;
    // cout << grid[0] << '\n';
    // cout << grid[1] << '\n';
    // cout << grid[2] << '\n';
    vector<pair<int, int>> ud;
    int la = 0;
    for(int i = 0; i < n; i++) {
        if(grid[0][i] != '0' || grid[1][i] != '1' || grid[2][i] != '0') {
            if(la != i) {
                ud.pb(mp(la, i - 1));
            }
            la = i + 1;
        }   
        // else {
        //     la++;
        // }
    }
    vector<pair<pair<int, int>, pair<int, int>>> uds;
    for(auto x: ud) {
        int lc = 2 - (grid[0][x.fi - 1] - '0') - (grid[2][x.fi - 1] - '0');
        int rc = 2 - (grid[0][x.se + 1] - '0') - (grid[2][x.se + 1] - '0');
        uds.pb(mp(x, mp(lc, rc)));
        // cout << x.fi << ' ' << x.se << ' ' << lc << ' ' << rc << '\n';
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1' || vi[i][j] != 0) continue;
            vi[i][j] = cnt;
            queue<pair<int, int>> bfs;
            bfs.push(mp(i, j));
            while(!bfs.empty()) {
                auto now = bfs.front();
                bfs.pop();
                for(int k = 0; k < 4; k++) {
                    int newx = now.fi + dx[k];
                    int newy = now.se + dy[k]; 
                    if(valid(newx, newy) && vi[newx][newy] == 0) {
                        vi[newx][newy] = cnt;
                        bfs.push(mp(newx, newy));
                    }
                }
            }
            cnt++;
        }
    }
    int mii[cnt + 5];
    int mxx[cnt + 5];
    for(int i = 0; i <= cnt; i++) {
        mii[i] = inf;
        mxx[i] = -1;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            mii[vi[i][j]] = min(mii[vi[i][j]], j);
            mxx[vi[i][j]] = max(mxx[vi[i][j]], j);
        }
    }
    int aaa[n + 5];
    int bbb[n + 5];
    for(int i = 0; i <= n; i++) aaa[i] = bbb[i] = 0;
    for(int i = 1; i < cnt; i++) {
        // cout << mii[i] << ' ' << mxx[i] << '\n';
        aaa[mii[i]]++;
        bbb[mii[i] + 1]++;
        bbb[mxx[i] + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        aaa[i] += aaa[i - 1];
        bbb[i] += bbb[i - 1];
    }
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << vi[i][j];
    //     }
    //     cout << '\n';
    // }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int an = 0;
        auto it = upper_bound(uds.begin(), uds.end(), mp(mp(l, inf), mp(inf, inf)));
        if(it != uds.begin()) {
            it = prev(it);
            auto huh = *it;
            if(huh.fi.se >= l) {
                an += 2 - huh.se.se;
                l = huh.fi.se + 1;
            }
        }
        it = upper_bound(uds.begin(), uds.end(), mp(mp(r, inf), mp(inf, inf)));
        if(it != uds.begin()) {
            it = prev(it);
            auto huh = *it;
            if(huh.fi.se >= r) {
                an += 2 - huh.se.fi;
                r = huh.fi.fi - 1;
            }
        }
        // cout << l << ' ' << r << '\n';
        if(l > r) {
            cout << "2\n";
        }
        else {
            // cout << an << '\n';
            an += bbb[l] + aaa[r] - aaa[l - 1];
            cout << an << '\n';
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}