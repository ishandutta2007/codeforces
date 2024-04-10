/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

map<int64, int> M;

const int64 mod = 2184057;
const int64 mod0 = 4343;
const int maxn = 218 * 1000;

int64 p[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cur = 0;
    vi v;
    int64 h = 0;
    p[0] = 1;
    for (int i = 1; i < maxn; ++i)
        p[i] = p[i - 1] * mod;
    for (int step = 0; k > 0; --k, ++step) {
        while (cur < sz(s) - 1) {
            if (s[cur] == '4' && s[cur + 1] == '7') {
                if (cur % 2 == 0) {
                    s[cur] = s[cur + 1] = '4';
                    h -= 3LL * p[cur + 1];
                    ++cur;
                    v.pb(0);
                } else {
                    s[cur] = s[cur + 1] = '7';
                    h += 3 * p[cur];
                    --cur;
                    if (cur < 0) cur = 0;
                    v.pb(1);
                }
                break;
            } else {
                ++cur;
            }
        }
        if (cur >= sz(s) - 1) break;


        int64 hh = h * mod0 + cur;
        if (M.count(hh)) {
            int per = step - M[hh];
            if (k > 2 * per + 1) {
                k %= per;
                if (k == 0) k += per;
            }
        } else {
            M[hh] = step;
        }
        
//        if (k > 100 && sz(v) >= 4 && v[sz(v) - 1] == 1 - v[sz(v) - 2] && v[sz(v) - 2] == 1 - v[sz(v) - 3] && v[sz(v) - 3] == 1 - v[sz(v) - 4]) {            
//            k %= 2;
//            k += 2;
//        }
    }
    cout << s << "\n";
    return 0;
}