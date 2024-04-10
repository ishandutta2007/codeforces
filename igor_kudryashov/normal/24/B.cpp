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

const int poi [] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int n, m;
map <string, pair <int, vector <int>>> r;
vector <pair <string, pair <int, vector <int>>> > v;

bool cmp1 (pair <string, pair <int, vector <int>>> &a, pair <string, pair <int, vector <int>>> &b) {
    if (a.second.first != b.second.first) return a.second.first > b.second.first;
    vector <int> t1 = a.second.second, t2 = b.second.second;
    int pl = 0;
    while (1) {
        if (pl > (int) v.size()) break;
        int kol1 = 0, kol2 = 0;
        forn(i, t1.size())
            if (t1[i] == pl) kol1++;
        forn(i, t2.size())
            if (t2[i] == pl) kol2++;
        if (kol1 != kol2) return kol1 > kol2;
        pl++;
    }
    return a.first < b.first;
}

bool cmp2 (pair <string, pair <int, vector <int>>> &a, pair <string, pair <int, vector <int>>> &b) {
    vector <int> t1 = a.second.second, t2 = b.second.second;
    int pl = 0;
    int k1 = 0, k2 = 0;
    forn(i, t1.size())
        if (t1[i] == pl) k1++;
    forn(i, t2.size())
        if (t2[i] == pl) k2++;
    if (k1 != k2) return k1 > k2;
    pl++;
    if (a.second.first != b.second.first) return a.second.first > b.second.first;
    while (1) {
        if (pl > (int) v.size()) break;
        int kol1 = 0, kol2 = 0;
        forn(i, t1.size())
            if (t1[i] == pl) kol1++;
        forn(i, t2.size())
            if (t2[i] == pl) kol2++;
        if (kol1 != kol2) return kol1 > kol2;
        pl++;
    }
    return a.first < b.first;
}

int main()
{
    cin >> n;
    forn(kt, n) {
        cin >> m;
        forn(i, m) {
            string s;
            cin >> s;
            if (i < 10) r[s].first += poi[i];
            r[s].second.push_back(i);
        }
    }
    for (map <string, pair <int, vector <int>>>::iterator yk = r.begin(); yk != r.end(); yk++) {
        v.pb(mp(yk->first, yk->second));
    }
    sort(v.begin(), v.end(), cmp1);
    cout << v[0].first << endl;
    sort(v.begin(), v.end(), cmp2);
    cout << v[0].first << endl;
    return 0;
}