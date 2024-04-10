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
#include <ctime>
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
const double PI = 3.1415926535897932384626433832795;

int n;
li fin;
li mx, my;
li ax[100005], ay[100005];
li dx, dy;
li ansx, ansy;

int main()
{
    cin >> n >> fin;
    cin >> mx >> my;
    forn(i, n) cin >> ax[i] >> ay[i];
    li occ = fin / n;
    int nw = fin % n;
    if (occ & 1) nw += n;
    li d = 1;
    for (int i = nw - 1; i >= 0; i--) {
        ansx += d * ax[i % n];
        ansy += d * ay[i % n];
        d *= -1;
    }
    ansx *= 2, ansy *= 2;
    if (fin & 1) ansx -= mx, ansy -= my; else ansx += mx, ansy += my;
    cout << ansx << " " << ansy << endl;
    return 0;
}