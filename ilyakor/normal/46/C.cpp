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

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int h = 0;
    for (int i = 0; i < sz(s); ++i)
        if (s[i] == 'H') ++h;
    int res = n;
    for (int i = 0; i < sz(s); ++i)
    {
        int cur = 0;
        for (int j = 0; j < h; ++j)
            if (s[(i + j) % sz(s)] != 'H')
                ++cur;
        res = min(res, cur);
    }
    cout << res << "\n";
    return 0;
}