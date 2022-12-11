#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

/*mt19937 rr(random_device{}());

void gen(string& s, int k) {
    s = "";
    for (int i = 0; i < k; ++i) {
        if (rr() % 4) {
            s += "E";
        } else {
            s += "N";
        }
    }
}*/

vector<string> str;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int h, w, k;
    /*h = 10, w = 15;
    k = 2;*/
    cin >> h >> w >> k;

    if (k == 1) {
        int total = 0;
        int ok = 0;
        for (int i = 0; i < 2 * h - 1; ++i) {
            string s;
            cin >> s;
            total += sz(s);
            for (int j = 0; j < sz(s); ++j) {
                if (s[j] == 'E') {
                    ++ok;
                }
            }
        }
        if (4 * ok >= 3 * total) {
            cout << "YES\n";
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    cout << "1 ";
                }
                cout << "\n";
            }
            return 0;
        }
        cout << "NO\n";
        return 0;
    }

    int tot = (h - 1) * w + (w - 1) * h;
    int o = h * (w - 1) + (h - 1) * ((w + 1) / 2);

    bool swapped = false;

    if (4 * o < 3 * tot) {
        vector<string> ss;
        for (int i = 0; i < 2 * h - 1; ++i) {
            string t;
            cin >> t;
            ss.pb(t);
        }
        for (int step = 0; step < 2 * w - 1; ++step) {
            if (step % 2 == 0) {
                string t = "";
                for (int i = 1; i < sz(ss); i += 2) {
                    t += ss[i][step / 2];
                }
                str.pb(t);
            } else {
                string t = "";
                for (int i = 0; i < sz(ss); i += 2) {
                    t += ss[i][step / 2];
                }
                str.pb(t);
            }
        }
        swap(h, w);
        swapped = true;
    } else {
        for (int i = 0; i < 2 * h - 1; ++i) {
            string t;
            cin >> t;
            str.pb(t);
        }
    }

    vector<vector<int> > ans(h, vector<int>(w));
    string s;
    int ptr = 0;
    //gen(s, w - 1);
    s = str[ptr++];
    int total = sz(s);
    ans[0][0] = 1;
    for (int j = 0; j < sz(s); ++j) {
        if (s[j] == 'E') {
            ans[0][j + 1] = ans[0][j];
        } else {
            ans[0][j + 1] = 3 - ans[0][j];
        }
    }
    int ok = sz(s);

    for (int i = 0; i + 1 < h; ++i) {
        string u, v;
        //gen(u, w);
        //gen(v, w - 1);
        u = str[ptr++];
        v = str[ptr++];
        total += sz(u) + sz(v);
        ok += sz(v);
        vector<int> tp(w);
        tp[0] = 1;
        for (int j = 0; j < sz(v); ++j) {
            if (v[j] == 'E') {
                tp[j + 1] = tp[j];
            } else {
                tp[j + 1] = 3 - tp[j];
            }
        }
        vector<int> x(5), y(5);
        for (int j = 0; j < w; ++j) {
            if (ans[i][j] == 1 && u[j] == 'E') {
                if (tp[j] == 1) {
                    ++x[1];
                } else {
                    ++y[1];
                }
            }
            if (ans[i][j] == 1 && u[j] == 'N') {
                if (tp[j] == 1) {
                    ++x[2];
                } else {
                    ++y[2];
                }
            }
            if (ans[i][j] == 2 && u[j] == 'E') {
                if (tp[j] == 1) {
                    ++x[3];
                } else {
                    ++y[3];
                }
            }
            if (ans[i][j] == 2 && u[j] == 'N') {
                if (tp[j] == 1) {
                    ++x[4];
                } else {
                    ++y[4];
                }
            }
        }

        int lf = x[1] + y[2] + y[3] + x[4];
        int rg = y[1] + x[2] + x[3] + y[4];
        if (lf > rg) {
            ok += lf;
            for (int j = 0; j < w; ++j) {
                if (tp[j] == 1) {
                    ans[i + 1][j] = 1;
                } else {
                    ans[i + 1][j] = 2;
                }
            }
        } else {
            ok += rg;
            for (int j = 0; j < w; ++j) {
                if (tp[j] == 1) {
                    ans[i + 1][j] = 2;
                } else {
                    ans[i + 1][j] = 1;
                }
            }
        }
    }

    assert(4 * ok >= 3 * total);

    cout << "YES\n";
    if (!swapped) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        for (int j = 0; j < w; ++j) {
            for (int i = 0; i < h; ++i) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }


}