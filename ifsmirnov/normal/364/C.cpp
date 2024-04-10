#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 100500;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
int lm[] = {5,100,100,100,100,100,100};

vi res;
void go(int s, int p, int mp, int lim) {
    if (s > lim) return;
    if (p == mp) {
        res.pb(s);
        return;
    }
    int cp = 1;
    int cnt = 0;
    while (s * cp < lim && ++cnt < lm[p]) {
        go(s*cp, p+1, mp, lim);
        cp *= primes[p];
    }
}

bool check(int p, int n) {
    forn(i, p) {
        int s = 0;
        forn(j, n) s += (res[j]%primes[i] == 0);
//         cout << s << " " << res.size() << endl;
        if (s < n/2) return false;
    }
    return true;
}

int main()
{
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

//     int n;
//     cin >> n;
//     go(1, 0, 6, n*n*2);
//     res.resize(n);
//     sort(all(res));
//     forn(i, res.size()) cout << res[i] << " ";
//     assert(check(6));
//     cout << endl;
// 
//     return 0;

    srand(0);

    int n;
    cin >> n;
//     for (int n = 10; n <= 5000; n++) {
//         cout << n << endl;
        int lim = n * n * 2;
        bool ok = false;
        for (int p = 2; p <= 6; ++p) {
            res.clear();
            go(1, 0, p, lim);
            if ((int)res.size() < n) continue;

            forn(III, 10) {
                random_shuffle(all(res));
                if (check(p, n)) {
                    res.resize(n);
                    sort(all(res));
                    forn(i, res.size()) cout << res[i] << " ";  cout << endl;
                    return 0;
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
//         if (!ok) {
//             cout << n << endl;
// //             break;
//         }

    return 0;

    sort(all(res));
    forn(i, res.size()) {
        cout << res[i] << " ";
    }
    cout << endl;

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}