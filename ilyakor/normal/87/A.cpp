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

int64 gcd(int64 x, int64 y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int main()
{
    int64 a, b;
    cin >> a >> b;
    int64 d = gcd(a, b);
    d = (a * b) / d;
    int64 x = d / a;
    int64 y = d / b;
    if (a < b)
        ++y;
    else
        ++x;
    if (x > y) cout << "Dasha\n";
    else if (x < y) cout << "Masha\n";
    else cout << "Equal\n";
    return 0;
}