#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 100 + 13;

int n;
map <string, int> numDef;
string defs[N];
string onlyOpers[N];

inline bool oper (char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

string withoutSpace (string t)
{
    string s = "";
    
    forn(i, sz(t))
        if (!isspace(t[i]))
            s.pb(t[i]);
            
    return s;
}

string withoutVars (string s)
{
    string res = "";
    string cur = "";
    
    forn(i, sz(s))
        if (oper(s[i]))
        {
            if (numDef.count(cur))
                res += cur;
                
            res.pb(s[i]);
            
            cur = "";
        } else
            cur.pb(s[i]);

    if (numDef.count(cur))
        res += cur;
            
    return res;
}

void parseDef (string s, int idx)
{
    int k = s.find('#');
    s = s.substr(k + 1);
    
    k = s.find('d');
    s = s.substr(k + 6);
    
    k = -1;
    forn(i, sz(s))
        if (s[i] != ' ')
        {
            k = i;
            break;
        }
        
    int k2 = k;
    while (s[k2] != ' ')
        k2++;
        
    string name = s.substr(k, k2 - k);
    
    while (s[k2] == ' ')
        k2++;
        
    string expr = withoutSpace(s.substr(k2));
    
    numDef[name] = idx;
    defs[idx] = withoutVars(expr);
}

inline bool has (const string& s, const char& c)
{
    forn(i, sz(s))
        if (s[i] == c)
            return true;
            
    return false;
}

bool bad (string t, char c1, char c2)
{
    string s = "";
    int bal = 0;
    
    forn(i, sz(t))
    {
        assert(oper(t[i]));
    
        if (t[i] == '(')
            bal++;
        else if (t[i] == ')')
            bal--;
        else if (bal == 0)
            s.pb(t[i]);
            
        assert(bal >= 0);
    }
    assert(bal == 0);
    
    if (c1 == '-' && (has(s, '+') || has(s, '-')))
        return true;
        
    if (c1 == '*' && (has(s, '+') || has(s, '-')))
        return true;
        
    if (c1 == '/' && !s.empty())
        return true;
        
    if ((c2 == '*' || c2 == '/') && (has(s, '+') || has(s, '-')))
        return true;
        
    return false;
}

set <string> used;

bool good (string s)
{
    if (used.count(s))
        return true;
    
    used.insert(s);

    string cur = "";
    
    char lastOper = '(';
    
    forn(i, sz(s))
        if (oper(s[i]))
        {
            if (numDef.count(cur) && (!good(defs[numDef[cur]]) || bad(onlyOpers[numDef[cur]], lastOper, s[i])))
                    return false;
            
            lastOper = s[i];
            cur = "";
        
        } else
            cur.pb(s[i]);
            
    if (numDef.count(cur) && (!good(defs[numDef[cur]]) || bad(onlyOpers[numDef[cur]], lastOper, ')')))
        return false;
            
    return true;
}

void setOnlyOpers ()
{
    onlyOpers[0] = defs[0];

    for1(idx, n - 1)
    {
        string res = "";
        string cur = "";
        
        forn(i, sz(defs[idx]))
            if (oper(defs[idx][i]))
                res.pb(defs[idx][i]);
            /*
            {
                if (numDef.count(cur))
                    res += onlyOpers[numDef[cur]];
                    
                res.pb(defs[idx][i]);
                
                cur = "";
            
            } else
                cur.pb(defs[idx][i]);
                
        if (numDef.count(cur))
            res += onlyOpers[numDef[cur]];
        */
            
        onlyOpers[idx] = res;
    }
}

int main()
{
    
    cin >> n;

    string s;

    getline(cin, s);
    
    forn(i, n)
    {
        getline(cin, s);
        
        parseDef(s, i);
    }
    
    getline(cin, s);
    
    s = withoutVars(withoutSpace(s));
    
    setOnlyOpers();
    
    if (good(s))
        puts("OK");
    else
        puts("Suspicious");

    return 0;
}