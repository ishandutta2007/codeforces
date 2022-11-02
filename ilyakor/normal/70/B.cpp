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

char buf[1005000];

int main()
{
    gets(buf);
    int n;
    sscanf(buf, "%d", &n);
    vi v;
    gets(buf);
    int cur = 0;
    for (int i = 0; buf[i]; ++i) {
        if (isspace(buf[i])) {
            if (cur) ++cur;
        } else if (buf[i] == '.' || buf[i] == '?' || buf[i] == '!') {
            ++cur;
            v.pb(cur);
            cur = 0;
        } else ++cur;
    }
    int res = 0, t = 0;
    for (int i = 0; i < sz(v); ++i) {
        if (v[i] > n) {
            printf("Impossible\n");
            return 0;
        }
        int add = 0;
        if (t) add = 1;
        if (t + v[i] + add <= n)
            t += v[i] + add;
        else ++res, t = v[i];
    }
    if (t) ++res;
    cout << res << "\n";
    return 0;
}