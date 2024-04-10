#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

int n;
int m;
int x1, y1, x2, y2;

int main () {
    scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
    while (!(x2 <= x1 && y2 <= y1)) {
        if (x1 - y1 > x2 - y2)
            x1--;
        else
        if (x1 - y1 < x2 - y2)  
            y1--;
        int nx2 = max (0, x2 - 1);
        int ny2 = max (0, y2 - 1);
        if (x1 < 0 || y1 < 0 || (x1 == nx2 && y1 == ny2)) {
            printf ("Polycarp\n");
            re 0;
        }
        x2 = nx2;
        y2 = ny2;
    }
    printf ("Vasiliy\n");
    return 0;
}