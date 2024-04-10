#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y, r, c, p;
        cin >> n >> m >> x >> y >> r >> c >> p;
        --x;
        --y;
        --r;
        --c;
        int good = (ll)p * obr(100) % mod;
        int bad = (1 + mod - good) % mod;
        int dx = 1;
        int dy = 1;
        vector<vector<vector<vector<int>>>> was(n, vector<vector<vector<int>>>(m, vector<vector<int>>(3, vector<int>(3, -1))));
        vi deltas;
        int now = 0;
        int end;
        while(true) {
            if(x == r || y == c) {
                deltas.push_back(now);
                now = 0;
            }
            if(was[x][y][dx + 1][dy + 1] != -1 && (x == r || y == c)) {
                end = was[x][y][dx + 1][dy + 1];
                break;
            }
            if(x == r || y == c) {
                was[x][y][dx + 1][dy + 1] = (int)deltas.size() - 1;
            }
            int x1 = x + dx;
            int y1 = y + dy;
            if(x1 < 0 || x1 >= n) {
                dx = -dx;
            }
            if(y1 < 0 || y1 >= m) {
                dy = -dy;
            }
            x = x + dx;
            y = y + dy;
            ++now;
        }
        int ans = 0;
        for(int i = 0; i <= end; i++) {
            int probbad = bin_pow(bad, i);
            ans = (ans + (ll)probbad * deltas[i]) % mod;
        }
        /*for(const auto& el : deltas) {
            cout << el << ' ';
        }
        cout << endl;
        cout << end << ' ' << ans << endl;*/
        int j = deltas.size() - end - 1;
        int p1 = bin_pow(bad, j);
        p1 = (mod + 1 - p1) % mod;
        p1 = obr(p1);
        for(int i = end + 1; i < deltas.size(); i++) {
            int here = (ll)bin_pow(bad, i) * deltas[i] % mod;
            here = (ll)here * p1 % mod;
            //cout << here << endl;
            ans = (ans + here) % mod;
        }
        cout << ans << '\n';
    }
}