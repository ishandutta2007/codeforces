#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

int64 gcd(int64 a, int64 b, int64& x, int64& y)
{
    if (!a)
    {
        x = 0, y = 1;
        return b;
    }
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int64 xx, yy;
    int64 d = gcd(b, a % b, xx, yy);
    y = xx - (a / b) * yy;
    x = yy;
    return d;
}

int main()
{
    int64 a, b, c, x, y;
    cin >> a >> b >> c;
    int64 d = gcd(abs(a), abs(b), x, y);
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    if (abs(c) % d)
    {
        printf("-1\n");
        return 0;
    }
    c /= d;
    c = -c;
    x *= c;
    y *= c;
    cout << x << " " << y << "\n";
    return 0;
}