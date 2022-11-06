#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;

int ch, zn;

int gcd (int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int get (int a, int k) {
    int res = 0;
    while (a >= k) {
        res += a % k;
        a /= k;
    }
    res += a;
    return res;
}

int main()
{
    int a;
    cin >> a;
    for (int i = 2; i < a; i++) {
        ch += get(a, i);
        zn++;
    }
    int t = gcd(ch, zn);
    ch /= t; zn /= t;
    printf("%d/%d\n", ch, zn);
    return 0;
}