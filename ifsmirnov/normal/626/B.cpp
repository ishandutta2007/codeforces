#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

int n;
int d[205][205][205];

void go(int x, int y, int z) {
    if (d[x][y][z]) return;
    d[x][y][z] = 1;
    if (x >= 2) go(x-1, y, z);
    if (y >= 2) go(x, y-1, z);
    if (z >= 2) go(x, y, z-1);
    if (x && y) go(x-1, y-1, z+1);
    if (x && z) go(x-1, y+1, z-1);
    if (y && z) go(x+1, y-1, z-1);
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    int n;
    string s;
    cin >> n;
    cin >> s;
    int c1 = 0, c2 = 0, c3 = 0;
    forn(i, n) {
        if (s[i] == 'B') ++c1;
        if (s[i] == 'G') ++c2;
        if (s[i] == 'R') ++c3;
    }
    go(c1, c2, c3);
    if (d[1][0][0]) cout << 'B';
    if (d[0][1][0]) cout << 'G';
    if (d[0][0][1]) cout << 'R';
    cout << endl;



#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}