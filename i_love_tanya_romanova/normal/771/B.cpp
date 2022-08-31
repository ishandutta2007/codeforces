/**
 *    author:  [itmo] enot.1.10
 *    created: 18.03.2017 18:36:36       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 111;

string genRand()
{
    string res = "";
    forn(i, 10)
    {
        res += (char)('a' + rand() % 26);
    }
    res[0] += 'A' - 'a';
    return res;
}

string s[N];
int a[N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    forn(i, k - 1) s[i] = genRand();    
    forn(i, n - k + 1)
    {
        char t[10];
        scanf("%s", t);
        if (t[0] == 'Y')
        {
            s[i + k - 1] = genRand();
        }
        else
        {
            s[i + k - 1] = s[i];
        }
    }
    forn(i, n) printf("%s%c", s[i].data(), " \n"[i + 1 == n]);

    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}