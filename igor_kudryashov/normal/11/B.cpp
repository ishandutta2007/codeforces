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

li x;


int main()
{
    cin >> x;
    if (x < 0) x = -x;
    li lf = 0, rg = INF;    
    while (rg - lf > 1) {
        li mid = ((lf + rg) >> 1);
        li t = ((mid * (mid + 1)) >> 1);
        if (t >= x) rg = mid; else lf = mid;
    }
    li ans = -1;
    for (li i = lf; i <= lf + 10; i++) {
        li t = ((i * (i + 1)) >> 1);
        if (t >= x) {
            bool chet = (i == 0 || (i % 4 == 0 || i % 4 == 3));
            if ((chet && (x % 2 == 0)) || (!chet && (x % 2 == 1))) {
                ans = i;
                break;
            }
        }
    }
    assert(ans >= 0);
    cout << ans << endl;
    return 0;
}