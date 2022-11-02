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



const double eps = 1E-6;



struct D {

    double x;

    int zc;

    D(){x = 0.0, zc = 0;}

    D(double y) {        

        if (abs(y) < eps)

            x = 0.0, zc = 1;

        else {

            x = log(abs(y)), zc = 0;

    }

    }

    D(double x, int zc) : x(x), zc(zc) {}

    D operator*(D d) {

        return D(x + d.x, zc + d.zc);

    }

    D inv() {

        return D(-x, -zc);

    }



    friend bool operator<(D d1, D d2) {

        return false;

    }



    double toD() {

    if (zc > 0) return 0;

        return exp(x);

    }

};



int main() {

    int n, m;

    cin >> n >> m;

    vector<pair<int, pair<int, D> > > v;

    for (int i = 0; i < n; ++i) {

        int a, h;

        int _l, _r;

        scanf("%d%d%d%d", &a, &h, &_l, &_r);

    double l = _l, r = _r;

    l = 100 - l, r = 100 - r;

//        assert(l >= 0 && l <= 100);

//        assert(r >= 0 && r <= 100);

        l *= 0.01;

        r *= 0.01;

//      l = 1.0 - l;

        //r = 1.0 - r;

    assert(l >= -eps);

    assert(r >= -eps);

        v.pb(mp(a - h, mp(1, D(l))));

        v.pb(mp(a, mp(1, D(l).inv())));



        v.pb(mp(a + 1, mp(1, D(r))));

        v.pb(mp(a + h + 1, mp(1, D(r).inv())));

    }

    for (int i = 0; i < m; ++i) {

        int b, z;

        scanf("%d%d", &b, &z);

        assert(z > 0.5);

        v.pb(mp(b, mp(2, D(z * 1.0))));

    }

    

    sort(all(v));

    double res = 0.0;

    D cur;

    for (int i = 0; i < sz(v); ++i) {

//        printf("%d %d: %lf %d\n", v[i].first, v[i].second.first, v[i].second.second.x, v[i].second.second.zc);

        if (v[i].second.first == 1) {

            cur = cur * v[i].second.second;

        } else {

            res += (v[i].second.second.toD()) * (cur.toD());

        }

    }

//    if (cur.zc > 0) while (1);

    if (abs(cur.toD() - 1.0) > eps) while (1);

    printf("%.10lf\n", res);

    return 0;

}