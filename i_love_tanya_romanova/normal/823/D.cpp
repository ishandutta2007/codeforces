#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define pb push_back
#define sz(a) ((int)(a).size())
#define pw(x) (1ll << (x))

using namespace std;


typedef double dbl;

typedef complex<dbl> num;


const int base = 20;
const int maxN = 1 << base;
int N;

num root[maxN];
int rev[maxN];

void init()
{
    int NN = maxN >> 1;
    forn(i, NN)
    {
        dbl alp = i * acos(-1) / NN;
        root[i + NN] = num(cos(alp), sin(alp));
    }
    for (int i = NN - 1; i > 0; --i) root[i] = root[2 * i];
}

void fft(num *a, num *f)
{
    forn(i, N) f[i] = a[rev[i]];
    for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
    {
        num z = f[i + j + k] * root[j + k];
        f[i + j + k] = f[i + j] - z;
        f[i + j] = f[i + j] + z;
    }
}

int A[maxN];
int B[maxN];
int C[maxN];
num a[maxN], f[maxN], b[maxN], g[maxN];

int D[maxN];

void mult()
{
    forn(i, N) a[i] = A[i];
    forn(i, N) b[i] = B[i];
    fft(a, f);
        //forn(i, N) eprintf("(%.4f %.4f)%c", root[i].real(), root[i].imag(), " \n"[i + 1 == N]);
        //forn(i, N) eprintf("(%.4f %.4f)%c", f[i].real(), f[i].imag(), " \n"[i + 1 == N]);
    fft(b, g);
        //forn(i, N) eprintf("(%.4f %.4f)%c", g[i].real(), g[i].imag(), " \n"[i + 1 == N]);
    forn(i, N) a[i] = f[i] * g[i] / (dbl)N;
    reverse(a + 1, a + N);
    fft(a, f);
    forn(i, N) C[i] = (int)round(f[i].real());

    if (0)
    {
        forn(i, N) forn(j, N) D[i + j] = 0;
        forn(i, N) forn(j, N) D[i + j] += A[i] * B[j];
        
        //forn(i, N) eprintf("(%.4f %.4f)%c", f[i].real(), f[i].imag(), " \n"[i + 1 == N]);
        //forn(i, N) eprintf("%d%c", C[i], " \n"[i + 1 == N]);
        //forn(i, N) eprintf("%d%c", D[i], " \n"[i + 1 == N]);
        
        forn(i, N) assert(D[i] == C[i]);
    }

}
       

char s[maxN];

int bad[maxN];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    init();

    if (0) {
        int ba = 2;
        N = pw(ba);
        
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (ba - 1));

        A[1] = 1;
        B[0] = 1;
        mult();
        //return 0;
    }


    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int n;
        scanf("%d%s", &n, s);
        int ba = 0;
        while (2 * n + 2 >= pw(ba)) ba++;
        N = pw(ba);

        //eprintf("N = %d\n", N);
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (ba - 1));
       
        forn(i, N) A[i] = 0, B[i] = 0;

        forn(i, n) if (s[i] == 'V') A[i] = 1;
        forn(i, n) if (s[i] == 'K') B[n - i] = 1;

        mult();

        for (int k = 1; k <= n; ++k)
        {
            bad[k] = (C[n - k] > 0) || (C[n + k] > 0);
        }

        for (int k = 1; k <= n; ++k) for (int j = k; j <= n; j += k) bad[k] |= bad[j];

        vector<int> ans;
        for (int k = 1; k <= n; ++k) if (!bad[k]) ans.pb(k);
        printf("%d\n", sz(ans));
        if (sz(ans))
        {
            forn(i, sz(ans)) printf("%d%c", ans[i], " \n"[i + 1 == sz(ans)]);
        }
        else printf("\n");
    }

        


        
        
            


    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}