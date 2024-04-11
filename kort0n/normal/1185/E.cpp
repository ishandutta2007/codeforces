#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
string field[4000500];
struct query {
    int sh, sw, th, tw;
    query(int a, int b, int c, int d) {
        sh = a;
        sw = b;
        th = c;
        tw = d;
    }
};

vector<query> queries;

void solve() {
    int H, W;
    cin >> H >> W;
    char maxi = 'a' - 1;
    for(int h = 1; h <= H; h++) {
        cin >> field[h];
        field[h] = "#" + field[h];
        for(int w = 1; w <= W; w++) {
            if(field[h][w] == '.') continue;
            chmax(maxi, field[h][w]);
        }
    }
    //cerr << maxi << endl;
    if(maxi == 'a' - 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    queries.clear();
    for(char moji = maxi; moji >= 'a'; moji--) {
        //cerr << "NOW: " << moji << endl;
        int sh = INF;
        int th = -INF;
        int sw = INF;
        int tw = -INF;
        for(int h = 1; h <= H; h++) {
            for(int w = 1; w <= W; w++) {
                if(field[h][w] == moji) {
                    chmin(sh, h);
                    chmax(th, h);
                    chmin(sw, w);
                    chmax(tw, w);
                }
            }
        }
        if(sh == INF) {
            bool ok = false;
            for(int h = 1; h <= H; h++) {
                if(ok) break;
                for(int w = 1; w <= W; w++) {
                    if(field[h][w] > moji) {
                        ok = true;
                        queries.emplace_back(h, w, h, w);
                        break;
                    }
                }
            }
            continue;
        }
        if(sh != th && sw != tw) {
            cout << "NO" << endl;
            return;
        }
        queries.emplace_back(sh, sw, th, tw);
        for(int h = sh; h <= th; h++) {
            for(int w = sw; w <= tw; w++) {
                if(field[h][w] == '.' || field[h][w] < moji) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    cout << queries.size() << endl;
    for(int i = queries.size() - 1; i >= 0; i--) {
        query now = queries[i];
        cout << now.sh << " " << now.sw << " " << now.th << " "<< now.tw << endl;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}