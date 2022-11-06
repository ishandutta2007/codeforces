#pragma comment(linker, "/stack:64000000")

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 * 1000 + 13;

int n, m, x, y;
pair <pt, int> a[N];
set <pt> s;
vector <pt> ans;
pt b[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> x >> y;
    
    forn(i, n)
    {
        int cur;
        scanf("%d", &cur);
        a[i] = mp(mp(cur - x, cur + y), i);
    }
    
    sort(a, a + n);
    
    forn(i, m)
        scanf("%d", &b[i].ft), b[i].sc = i;
        
    sort(b, b + m);
    
    int it = 0;
    
    forn(i, m)
    {
        while (it < n && a[it].ft.ft <= b[i].ft)
            s.insert(mp(a[it].ft.sc, a[it].sc)), it++;
            
        while (true)
        {
            if (s.empty())
                break;
            
            pt cur = *s.begin();
            s.erase(s.begin());
            
            if (cur.ft < b[i].ft)
                continue;
                
            ans.pb(mp(cur.sc, b[i].sc));
            break;
        }
    }
    
    cout << sz(ans) << endl;
    
    forn(i, sz(ans))
        printf("%d %d\n", ans[i].ft + 1, ans[i].sc + 1);

    return 0;
}