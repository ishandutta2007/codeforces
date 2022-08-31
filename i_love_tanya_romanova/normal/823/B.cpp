#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define pb push_back


using namespace std;

typedef vector<int> vi;


struct fen
{
    vi t;
    int n;

    fen(){}
    fen(int _n)
    {        
        n = _n + 1;
        t = vi(n);
    }
    
    int get(int x)
    {
        x++;
        int res = 0;
        for (; x > 0; x -= x & -x) res += t[x];
        return res;
    }

    int get(int l, int r)
    {
        return get(r) - get(l - 1);
    }

    void upd(int x, int dx)
    {
        x++;
        for (; x < n; x += x & -x) t[x] += dx;
    }
};

         
        

const int N = 1e5 + 10;

char s[N];
fen f[4][11][11];
char ss[123];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    scanf("%s", s);
    int n = strlen(s);
    map<char, int> M;
    M['A'] = 0;
    M['C'] = 1;
    M['G'] = 2;
    M['T'] = 3;

    for (int e = 1; e <= 10; e++)
    {
        forn(r, e)
        {
            int sz = max(0, (n - r) / e + 10);
            forn(k, 4)
            {
                f[k][e][r] = fen(sz);
            }
        }
        forn(i, n) f[M[s[i]]][e][i % e].upd(i / e, 1);
    }

    int q;
    scanf("%d", &q);
    forn(_, q)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x;
            char c;
            scanf("%d %c", &x, &c);
            --x;
            int val = M[c];
            if (s[x] == c) continue;
            int was = M[s[x]];
            s[x] = c;

            for (int e = 1; e <= 10; ++e)
            {
                f[was][e][x % e].upd(x / e, -1);
                f[val][e][x % e].upd(x / e, 1);
            }
        }
        else
        {
            int l, r;
            scanf("%d%d%s", &l, &r, ss);
            int e = strlen(ss);
            --l, --r;
            int res = 0;
            forn(ii, e)
            {
                int want = M[ss[ii]];
                int i = (l + ii) % e;
                int L = l;
                int R = r;
                while (L % e != i) L++;
                while ((R + e) % e != i) R--;

                if (L > R) continue;

                int val = f[want][e][i].get(L / e, R / e);
                res += val;
            }
            printf("%d\n", res);
        }
    }
                

    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}