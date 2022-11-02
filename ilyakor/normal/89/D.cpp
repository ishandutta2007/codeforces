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

typedef int64 D;

const double eps = 1E-9;

struct P {
    D x, y, z;
    P(){}
    P(D x, D y, D z) : x(x), y(y), z(z) {}
    void read() {
        cin >> x >> y >> z;
    }
    P operator-(P p) {
        return P(x - p.x, y - p.y, z - p.z);
    }
    D len2() {
        return x * x + y * y + z * z;
    }
    D operator&(P p) {
        return x * p.x + y * p.y + z * p.z;
    }
};

double cross(P c0, P v, D r, P p) {
    P tmp = c0 - p;
    D rs2 = r * r;
    D a = v.len2();
    D b = 2LL * (tmp & v);
    D c = tmp.len2() - rs2;
    D d = b * b - 4LL * a * c;
    if (d < 0) return 1E100;
    double r1 = (sqrt(abs(d + 0.)) - b) / (2. * a);
    double r2 = (-sqrt(abs(d + 0.)) - b) / (2. * a);
    double res = 1E100;
    if (r1 > eps) res = min(res, r1);
    if (r2 > eps) res = min(res, r2);
    return res;
}

double cross(P c, P v, D r, P p, D ri) {
    r += ri;
    return cross(c, v, r, p);
}

int main()
{
    P c0, v0;
    D r;
    c0.read();
    v0.read();
    cin >> r;
    int n;
    cin >> n;
    double res = 1E100;
    for (int it = 0; it < n; ++it) {
        P c;
        c.read();
        D ri;
        cin >> ri;
        int m;
        cin >> m;       
        res = min(res, cross(c0, v0, r, c, ri));
        //cerr << res << "\n";
        for (int i = 0; i < m; ++i) {
            P np;
            np.read();
            np.x += c.x;
            np.y += c.y;
            np.z += c.z;
            res = min(res, cross(c0, v0, r, np));
            //cerr << res << "\n";
        }
        
    }
    if (res > 1E50) printf("-1\n");
    else printf("%.10lf\n", res);
    return 0;
}