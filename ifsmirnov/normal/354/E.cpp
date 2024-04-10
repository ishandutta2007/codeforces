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

map<i64, int> d;

bool go(i64 x) {
    if (x == 0) {
        return true;
    }
    if (d.count(x)) {
        return d[x] != -1;
    }
    forn(i, 7) forn(j, 7-i) {
        int a = i*7 + j*4;
        if (x%10 != a%10 || a > x) {
            continue;
        }
        if (go((x-a)/10)) {
            d[x] = i * 10 + j;
            return true;
        }
    }
    d[x] = -1;
    return false;
}

void out(const string& s) {
    int p = 0;
    while (p < (int)s.length() - 1 && s[p] == '0') ++p;
    while (p < (int)s.length()) printf("%c", s[p++]);
    printf(" ");
}

void print_answer(i64 x) {
    vector<string> res(6);
    while (x) {
        int q = d[x];
        int c7 = q/10, c4 = q%10;
        for (int i = 0; i < c7; ++i) res[i].pb('7');
        for (int i = 0; i < c4; ++i) res[i+c7].pb('4');
        for (int i = c7+c4; i < 6; ++i) res[i].pb('0');
        x = (x-c4*4-c7*7) / 10;
    }
    forn(i, 6) reverse(all(res[i]));
    forn(i, 6) out(res[i]); printf("\n");
}

int main()
{
//     freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    forn(i, t) {
        i64 x;
        cin >> x;
        d.clear();
        if (go(x)) {
            print_answer(x);
        } else {
            printf("-1\n");
        }
    }

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}