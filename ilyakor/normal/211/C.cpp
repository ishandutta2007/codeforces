#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <bitset>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

int64 d[200][2][2];

int main() {
    string s;
    cin >> s;
    vi v;
    for (int i = 0; i < sz(s); ++i)
        v.pb(s[i] - 'A');
    int64 res = 0;
    for (int it = 0; it < 2; ++it) {
        memset(d, 0, sizeof(d));
        d[0][v[0]][v[0]] = 1;
        if (v[0] == 1 && v[1] == 0) d[1][0][1] = 1;
        for (int i = 0; i + 1 < sz(v); ++i) {
            int cur = v[i + 1];
            for (int p = 0; p < 2; ++p)
                for (int j = 0; j < 2; ++j)
                    if (d[i][p][j] > 0) {
                        if (j != 0 || cur != 1)
                            d[i + 1][p][cur] += d[i][p][j];
                        if (i + 2 < sz(v) && cur == 1 && v[i + 2] == 0) {
                            d[i + 2][p][1] += d[i][p][j];
                        }
                }
        }
        for (int p = 0; p < 2; ++p){
            for (int q = 0; q < 2; ++q)
                if (it == 1 || q != 0 || p != 1)
                    res += d[sz(v) - 1][p][q];
        }
        if (v[0] == 0 && v[sz(v) - 1] == 1) {
            vi w;
            for (int i = 1; i + 1 < sz(v); ++i)
                w.pb(v[i]);
            v = w;
        }
        else break;
    }
    cout << res << "\n";
    return 0;
}