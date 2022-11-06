#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
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
#include <list>
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

string notes[24] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

string ans[] = {"major", "minor"};

int dist (string s1, string s2)
{
    forn(i, 24)
        if (notes[i] == s1)
        {
            for (int j = i; j < 24; j++)
                if (notes[j] == s2)
                    return j - i;
                    
            throw;
        }
        
    throw;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    string s[3];
    vector <int> perm;
    
    forn(i, 3)
    {
        cin >> s[i];
        perm.pb(i);
    }
    
    int type = -1;
    
    do 
    {
        vector <string> ss;
        forn(i, 3)
            ss.pb(s[perm[i]]);
            
        if (dist(ss[0], ss[1]) == 4 && dist(ss[1], ss[2]) == 3)
            type = 0;
        else if (dist(ss[0], ss[1]) == 3 && dist(ss[1], ss[2]) == 4)
            type = 1;
    
    } while (next_permutation(all(perm)));
    
    if (type == -1)
        puts("strange");
    else
        puts(ans[type].c_str());

    return 0;
}