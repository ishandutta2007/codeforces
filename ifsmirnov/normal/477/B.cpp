#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

vi gen(int n) {
    int s = 1;
    vi res;
    forn(i, n) {
        res.pb(s);
        res.pb(s+1);
        res.pb(s+2);
        res.pb(s+4);
        s += 6;
    }
    return res;
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    vi res = gen(n);
    cout << *max_element(all(res)) * k << "\n";
    forn(i, n*4) {
        cout << res[i]*k << " \n"[i%4 == 3];
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}