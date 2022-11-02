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

char s[1000 * 1000];

int64 d[300];

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        ++d[s[i]];
    int64 res = 0;
    for (int i = 0; i < 300; ++i)
        if (d[i])
            res += d[i] * d[i];
    cout << res << "\n";
    return 0;
}