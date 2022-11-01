#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

struct hmap {
    static int hash(unsigned x) {
        return ((x*3)<<11) ^ (x>>2) ^ ((x*1000000007));
    }
    int sz;
    int cnt;
    int *ht, *val;
    hmap() :
        sz(4),
        cnt(0),
        ht(new int[sz]),
        val(new int[sz])
    {
        memset(ht, -1, sz * sizeof(int));
        memset(val, 0, sz * sizeof(int));
    }
    ~hmap() {
        delete[] ht;
        delete[] val;
    }

    int getpos(int x) {
        if (cnt > sz / 2) {
            increase_capacity();
        }
        int i = abs(hash(x)) % sz;
        while (ht[i] != x && ht[i] != -1) {
            if (++i == sz) {
                i = 0;
            }
        }
        if (ht[i] == -1) {
            ht[i] = x;
            ++cnt;
        }
        return i;
    }

    int& operator[](int x) {
        int pos = getpos(x);
        return val[pos];
    }

    void increase_capacity() {
        int old_sz = sz;
        sz *= 2;
        int *ht1 = new int[sz];
        int *val1 = new int[sz];
        swap(ht, ht1);
        swap(val, val1);
        memset(ht, -1, sz * sizeof(int));
        memset(val, 0, sz * sizeof(int));

        cnt = 0;
        for (int i = 0; i < old_sz; ++i) {
            if (ht1[i] != -1) {
                (*this)[ht1[i]] = val1[i];
            }
        }
    }
};

template<typename T>
void last_digits(T &x, int &a, int &b) {
    T t = x / 10;
    a = x - t * 10;
    x = t;
    t = x / 10;
    b = x - t * 10;
    x = t;
}

template<typename T>
bool check(T x) {
    if (x < 100) return x%11 != 0;
    int a, b;
    last_digits(x, a, b);
//     int a = x%10; x /= 10;
//     int b = x%10; x /= 10;
    if (a == b) return false;
    while (x) {
        int c = x%10; x /= 10;
        if (c == b || (b<c) != (b<a)) return false;
        a = b;
        b = c;
    }
    return true;
}

bool check_k(int x, int k) {
    int a, b;
    last_digits(x, a, b);
//     int a = x%10; x /= 10;
//     int b = x%10; x /= 10;
    if (a == b) return false;
    forn(i, k-2) {
        int c = x%10; x /= 10;
        if (c == b || (b<c) != (b<a)) return false;
        a = b;
        b = c;
    }
    return true;
}

i64 n, k;
hmap d[10][2];
// unordered_map<int, int> d[10][2];

void fill() {
    forn(i, 10000000) if (check_k(i, 7)) {
        int a = i / 1000000;
        int b = (i % 1000000) / 100000;
        ++d[a][a<b][i%n];
    }
}

i64 solve_small() {
    forn(i, 10000000) {
        if (i % n == 0 && check<int>(i)) {
            if (!--k) {
                return i;
            }
        }
    }
    return 0;
}

i64 solve() {
    fore(st, 1, 9999999) if (check<int>(st)) {
        i64 rem = n - (((i64)st * 10000000) % n);
        if (rem == n) {
            rem = 0;
        }
        if (rem >= 10000000) {
            continue;
        }
        int a = (st % 100) / 10, b = st % 10;
        int local_s = 0;
        if (st < 10) {
            forn(t, 10) if (t != b) {
                local_s += d[t][t<b][rem];
            }
        } else if (a < b) {
            forn(t, b) {
                local_s += d[t][t<b][rem];
            }
        } else if (a > b) {
            for (int t = b+1; t < 10; ++t) {
                local_s += d[t][t<b][rem];
            }
        }
        if (local_s >= k) {
//             cout << "st = " << st << endl; 
            forn(i, 10000000) {
                i64 x = (i64)st * 10000000 + i;
                if (x%n == 0 && check<i64>(x)) {
                    if (!--k) {
                        return x;
                    }
                }
            }
            assert(false);
        }
        k -= local_s;
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    i64 res = solve_small();
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    fill();
    if (res == 0) {
//         cout << "running solve" << endl;
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
        res = solve();
    }
    assert(res % n == 0);
    assert(res == 0 || check(res));
    if (res == 0) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

//     i64 n, k;
//     cin >> n >> k;
//     cout << kth(n, k) << endl;

    /*
    forn(i, 10) {
        d[1][0][i] = d[1][1][i] = 1;
    }
    d[1][0][0] = d[1][1][0] = 0;
    for (int n = 1; n <= 12; ++n) {
        forn(k, 10) {
            forn(p, 10) if (p != k) {
                forn(t, 2) if ((p<k) == t) {
                    d[n+1][0][p] += d[n][k][t];
                    d[n+1][1][p] += d[n][k][t];
                }
            }
        }
    }
    i64 res = 0;
    forn(k, 10) forn(t, 2) {
        res += d[13][t][k];
    }
    cout << res << endl;
    */



#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}