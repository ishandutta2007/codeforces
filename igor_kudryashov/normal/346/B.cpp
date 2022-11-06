#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 + 13;

inline vector<int> calcp(char* s, int n)
{
    vector<int> p(n, 0);

    forl(i, n - 1)
    {
        p[i] = p[i - 1];
        
        while (p[i] > 0 && s[p[i]] != s[i]) p[i] = p[p[i] - 1];
        
        p[i] += s[i] == s[p[i]];
    }

    return p;
}

char s[3][N];
int szs[3];

inline bool read()
{
    forn(i, 3)
    {
        assert(scanf("%s", s[i]) == 1);
        szs[i] = strlen(s[i]);
    }
    
    return true;
}

int next[N][30];

inline int getPref (int len)
{
    vector <int> p = calcp(s[2], len);
    return p[len - 1];
}

inline void prepare ()
{
    forn(pref, szs[2])
    {
        char old = s[2][pref];
        
        forn(alp, 26)
        {
            if (char(alp + 'A') == old)
                next[pref][alp] = pref + 1;
            else
            {
                s[2][pref] = char(alp + 'A');
                next[pref][alp] = getPref(pref + 1);
            }
        }
        
        s[2][pref] = old;
    }
}

int d[N][N][N];
char p[N][N][N];
char pp[N][N][N];

inline void solve()
{
    prepare();
    
    memset(d, -1, sizeof(d));
    d[0][0][0] = 0;
    
    //forn(i, szs[2] + 1) { forn(j, 26) cerr << next[i][j] << ' '; cerr << endl; }
    
    forn(i, szs[0] + 1)
        forn(j, szs[1] + 1)
            forn(k, szs[2] + 1)
            {
                int& dv = d[i][j][k];
                if (dv == -1) continue;
                
                if (i < szs[0] && d[i + 1][j][k] < dv)
                {
                    d[i + 1][j][k] = dv;
                    p[i + 1][j][k] = 0;
                }
                
                if (j < szs[1] && d[i][j + 1][k] < dv)
                {
                    d[i][j + 1][k] = dv;
                    p[i][j + 1][k] = 1;
                }
                
                if (i < szs[0] && j < szs[1] && s[0][i] == s[1][j] && next[k][s[0][i] - 'A'] < szs[2])
                {
                    //cerr << i << ' ' << j << ' ' << k << ' ' << s[0][i] - 'A' << endl;
                    int nk = next[k][s[0][i] - 'A'];
                    if (d[i + 1][j + 1][nk] < dv + 1)
                    {
                        d[i + 1][j + 1][nk] = dv + 1;
                        p[i + 1][j + 1][nk] = 2;
                        pp[i + 1][j + 1][nk] = char(k);
                    }
                }
            }
            
    int ansVal = 0;
    int ansi = szs[0], ansj = szs[1], ansk = -1;
    
    forn(i, szs[2]) if (ansVal < d[szs[0]][szs[1]][i]) ansVal = d[szs[0]][szs[1]][i], ansk = i;
    
    if (ansVal == 0)
    {
        puts("0");
        return;
    }
    
    string ans = "";
    
    while (true)
    {
        if (ansi == 0 && ansj == 0) break;
        
        if (p[ansi][ansj][ansk] == 0) ansi--;
        else if (p[ansi][ansj][ansk] == 1) ansj--;
        else if (p[ansi][ansj][ansk] == 2)
        {
            ans.pb(s[0][ansi - 1]);
            ansk = pp[ansi][ansj][ansk];
            ansi--;
            ansj--;            
            
        } else throw;
    }
    
    reverse(all(ans));
    assert(sz(ans) == ansVal);
    
    puts(ans.c_str());
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();

#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}