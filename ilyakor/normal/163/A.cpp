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

const int64 mod = 1000000007LL;

const int maxn = 5700;

int64 d[maxn];
int64 dd[maxn];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    memset(d, 0, sizeof(d));
    d[0] = 1;

    int64 res = 0;

    for (int i = 0; i < sz(s1); ++i) {
        char c = s1[i];
        memset(dd, 0, sizeof(dd));
        dd[0] = 1;

        int64 s = 0;
        for (int j = 0; j <= sz(s2); ++j) {
            if (j > 0 && s2[j - 1] == c)
                dd[j] = s;
            s += d[j];
            s %= mod;
        }

        memcpy(d, dd, sizeof(dd));

        for (int j = 1; j <= sz(s2); ++j) {
            res += d[j];
            res %= mod;
        }
    }

    cout << res << "\n";
    return 0;
}