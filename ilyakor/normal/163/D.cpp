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

vector<pair<int64, int> > v;

vector<int64> w;

void gen(int ind, int64 cur) {

    if (sz(w) > 5000 && cur > (int64)(1E9)) return;

    if (ind >= sz(v)) {
        w.pb(cur);
        return;
    }

    for (int i = 0; i <= v[ind].second; ++i) {
        gen(ind + 1, cur);
        cur *= v[ind].first;
    }
}

bool check(int64 x, int64 y) {
    int64 t = (int64) sqrt(y + 1.0);
    t += 10;
    if (x > t) return false;
    return x * x <= y;
}

map<int64, vector<int64> > M;

int main()
{
    int nc;
    cin >> nc;
    for (int it = 0; it < nc; ++it) {
        int k;
        cin >> k;
        vector<pair<int64, int> > v(k);
        int64 n = 1;
        for (int i = 0; i < k; ++i) {
            cin >> v[i].first >> v[i].second;
            
        }

        for (int i = 0; i < k; ++i) 
            for (int j = 0; j < v[i].second; ++j)
                n *= v[i].first;

        if (M.count(n)) {
            vector<int64> res = M[n];
            for (int i = 0; i < sz(res); ++i) cout << res[i] << " ";
            cout << "\n";
            continue;
        }

        (::v) = v;
        w.clear();
        gen(0, 1);

        sort(all(w));
        /*cerr << n << "\n";

        for (int i = 0; i < 100; ++i) {
            cerr << w[i] << "\n";
        }

        for (int i = 0; i < 100; ++i) {
            cerr << w[sz(w) - 1 - i] << "\n";
        }*/

        

        //cerr << sz(w) << "\n";
        int u = 0;

        
        int64 opt = 2LL * n + 1LL;
        int64 a = 1, b = 1, c = w[sz(w) - 1];

        {
            double tmp = pow((double) n, 1. / 3.);
            int u1 = 0;
            while (u1 < sz(w) && w[u1] < tmp) ++u1;
            if (u1 >= sz(w)) --u1;

            int64 m = n / w[u1];
            int u2 = 0;
            while (u2 < sz(w) && check(w[u2], m)) ++u2;
            if (u2 >= sz(w)) --u2;
            while (m % w[u2]) --u2;

            int64 A = w[u1];
            int64 B = w[u2];
            int64 C = m / w[u2];
            int64 val = A * B + A * C + B * C;
            if (val <  opt) opt = val, a = A, b = B, c = C;
        }

        

        for (int i = sz(w) - 1; i >= 0; --i) {
        //for (int i = 0; i < sz(w); ++i) {
            int64 x = n / w[i];
            //if (w[i] * w[sz(w) - 1 - i] != n) cerr << "AAA\n";
            //int64 x = w[i];
            if ((2.0 * n / sqrt(x + 0.) + x) / opt > 1.00001) continue;
            while (u + 1 < sz(w) && check(w[u + 1], x)) ++u;
            int j = u;
            while (x % w[j]) --j;

            int64 A = w[i], B = x / w[j], C = w[j];
            int64 val = A * B + A * C + B * C;
            if (val <  opt) opt = val, a = A, b = B, c = C;
        }

        cout << (2LL * opt) << " " << a << " " << b << " " << c << "\n";

        vector<int64> res;
        res.pb(2LL * opt);
        res.pb(a);
        res.pb(b);
        res.pb(c);
        M[n] = res;
    }
    return 0;
}