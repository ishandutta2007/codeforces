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
#include <bitset>
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
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
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

const int N = 1000 * 1000 + 3;

int n1, n2, n;
char s1[N], s2[N];
int com;

int gcd (int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

bool bit (char c1, char c2)
{
    if (c1 == 'R' && c2 == 'S') return true;
    if (c1 == 'S' && c2 == 'P') return true;
    if (c1 == 'P' && c2 == 'R') return true;
    return false;
}

pt calc ()
{
    pt ans = mp(0, 0);
    
    forn(i, com)
        if (bit(s1[i], s2[i]))
            ans.sc++;
        else if (bit(s2[i], s1[i]))
            ans.ft++;
            
    return ans; 
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d\n", &n);
    
    gets(s1);
    gets(s2);
    
    n1 = strlen(s1);
    n2 = strlen(s2);
    
    com = n1 / gcd(n1, n2) * n2;
    
    forn(i, com)
    {
        s1[i] = s1[i % n1];
        s2[i] = s2[i % n2];
    }
    
    int cntCom = n / com;
    
    pt ans = calc();
    ans.ft *= cntCom;
    ans.sc *= cntCom;
    
    forn(i, n % com)
        if (bit(s1[i], s2[i]))
            ans.sc++;
        else if (bit(s2[i], s1[i]))
            ans.ft++;
            
    printf("%d %d\n", ans.ft, ans.sc);

    return 0;
}