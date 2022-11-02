#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int main()
{
    int64 x, y;
    cin >> x >> y;
    //if (x == 3 && y == 14) cout << "44\n";
    //if (x == 27 && y == 12) cout << "48\n";
    //if (x == 100 && y == 200) cout << "102\n";
    int64 z = 0;
    while (y) z = z * 10LL + (y % 10), y /= 10;
    int64 res = z + x;
    cout << res << "\n";
    return 0;
}