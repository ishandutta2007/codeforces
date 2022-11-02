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



int main() {

    string s;

    cin >> s;

    vi v(10, 0);

    for (int i = 0; i < sz(s); ++i)

        v[s[i] - '0']++;



    vi w[2];

    w[0] = v;

    w[1] = v;



    string r[2];

    vi _vi;

    for (int i = 0; i < 10; ++i)

        _vi.pb(i);



    int opt = -1, ov = 1, fz = 0;



    for (int i = 1; i < 10; ++i) {

        if (!w[0][i] || !w[1][10 - i]) continue;

        int cur = 1;



        vi W[2];

        W[0] = w[0], W[1] = w[1];

        W[0][i]--, W[1][10 - i]--;





        for (int j = 0; j < 10; ++j) {

            int k = 9 - j;

            int x = min(W[0][j], W[1][k]);

            cur += x;

            W[0][j] -= x, W[1][k] -= x;

        }



        cur += min(W[0][0], W[1][0]);



        if (cur > opt)

            opt = cur, ov = i, fz = min(W[0][0], W[1][0]);

    }



    swap(_vi[1], _vi[ov]);

//    rotate(_vi.begin(), _vi.begin() + 1, _vi.end());

    _vi.pb(0);



    bool isf = true;

    for (int _i = 0; _i < sz(_vi); ++_i) {

        int i, j, x;

        if (_i == 0) i = 0, j = 0, x = fz; else

        if (isf) {

            i = _vi[_i];

            j = (10 - i) % 10;

            x = min(w[0][i], w[1][j]);

            x = min(x, 1);

            if (!x) continue;

        } else {

            i = _vi[_i];

            j = (9 - i) % 10;

            x = min(w[0][i], w[1][j]);

        }

        for (int k = 0; k < x; ++k) {

            r[0] += '0' + i;

            r[1] += '0' + j;

            w[0][i]--, w[1][j]--;            

        }

        if (_i && isf) isf = false, --_i;

    }

    for (int ind = 0; ind < 2; ++ind)

        for (int i = 0; i < 10; ++i)

            for (int j = 0; j < w[ind][i]; ++j)

                r[ind] += '0' + i;

    for (int ind = 0; ind < 2; ++ind) {

        reverse(all(r[ind]));

        cout << r[ind] << "\n";

    }

    return 0;

}