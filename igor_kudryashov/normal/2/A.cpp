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

int n;
map <string, vector <pt> > ss;

int main()
{
    cin >> n;
    forn(i, n) {
        string name;
        int sc;
        cin >> name >> sc;
        if (ss.count(name) == 0) {
            ss[name].push_back(mp(sc, i));
        } else {
            pt t = ss[name].back();
            t.first += sc;
            t.second = i;
            ss[name].push_back(t);
        }
    }
    int maxv = -INF, day = INF;
    string ans = "";
    for (map <string, vector <pt>> ::iterator yk = ss.begin(); yk != ss.end(); yk++) {
        vector <pt> t = yk->second;
        int locmax, curd;
        locmax = t.back().first;
        curd = t.back().second;
        forn(i, t.size())
            if (t[i].first >= locmax) curd = min(curd, t[i].second);
        if (locmax > maxv || (locmax == maxv && curd < day)) {
            maxv = locmax;
            day = curd;
            ans = yk->first;
        }
    }
    cout << ans << endl;
    return 0;
}