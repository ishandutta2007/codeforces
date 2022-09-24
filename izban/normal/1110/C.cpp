#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

map<int, int> mp;

const int prec[] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int fast(int x) {
    if (!mp.count(x)) {
        int y = 0;
        for (int j = 0; j < 26; j++) if ((1 << j) <= x) y |= 1 << j;

        if (x == y) {
            int bits = 0;
            int xx = x;
            while (xx) {
                xx /= 2;
                bits++;
            }
            y = prec[bits];
        }
        mp[x] = y;
    }
    return mp[x];
}

int slow(int a) {
    int res = 0;
    for (int b = 1; b < a; b++) res = max(res, __gcd(a ^ b, a & b));
    return res;
}



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    /*for (int i = 0; i <= 25; i++) {
        int x = (1 << i) - 1;
        cout << slow(x) << ",";
    }
    return 0;*/
    /*for (int i = 2; i <= 5e3; i++) {
        if (fast(i) != slow(i)) {
            cout << i << endl;
            cout << fast(i) << " instead of "<< slow(i) << endl;
            return 0;
        }
    }*/

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << fast(x) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}