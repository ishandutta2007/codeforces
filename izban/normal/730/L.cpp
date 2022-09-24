/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 12:31:52       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int rev(int a, int m)
{
    if (a == 1) return 1;
    return (1 - rev(m % a, a) * (ll)m) / a + m;
}

struct number
{
    int val, len;
    int st, en;
    vi pref, suf;
};

char s[N];
int pos = 0;

inline number parse_number()
{                     
    int en = pos;
    while ('0' <= s[en] && s[en] <= '9') en++;
    assert(pos < en);
    number res;
    res.len = en - pos;
    res.pref = vi(res.len + 1);
    res.suf = vi(res.len + 1);
    forn(i, res.len) res.pref[i + 1] = (res.pref[i] * 10LL + s[pos + i] - '0') % mod;
    int pn = 1;
    for (int i = res.len - 1; i >= 0; --i)
    {
        res.suf[i] = (res.suf[i + 1] + pn * (ll)(s[pos + i] - '0')) % mod;
        pn = pn * 10LL % mod;
    }
    res.st = pos, res.en = en;
    res.val = res.pref[res.len];
    pos = en;
    return res;
}

struct brackets
{
    int val;

    int st, en;

    brackets(){}
    brackets(int vval, int sst, int een): val(vval), st(sst), en(een) {}
};

inline int getVal(pair<brackets, number> &a)
{
    if (a.F.val != -1) return a.F.val;
    return a.S.val;
}

struct mul
{
    vector<pair<brackets, number>> v;
    vi pref, suf;
    vi mid, cnt;
    int val;

    int st, en;

    void calc()
    {
        int len = sz(v);
        pref = vi(len + 1);
        suf = vi(len + 1);
        pref[0] = 1;
        for (int i = 0; i < len; ++i) pref[i + 1] = pref[i] * (ll)getVal(v[i]) % mod;
        suf[len] = 1;
        for (int i = len - 1; i >= 0; --i) suf[i] = suf[i + 1] * (ll)getVal(v[i]) % mod;
        val = pref[len];

        mid = vi(len + 1);
        cnt = vi(len + 1);
        mid[0] = 1;
        for (int i = 0; i < len; ++i)
        {
            int VAL = getVal(v[i]);
            mid[i + 1] = mid[i];
            cnt[i + 1] = cnt[i];
            if (VAL == 0) cnt[i + 1]++;
            else mid[i + 1] = mid[i + 1] * (ll)VAL % mod;
        }
    }

    int getMid(int l, int r)
    {
        if (l >= r) return 1;
        int dcnt = cnt[r] - cnt[l];
        if (dcnt) return 0;
        return mid[r] * (ll)rev(mid[l], mod) % mod;
    }
};

struct add
{
    vector<mul> v;
    vi pref, suf;

    int val;
    int st, en;
    
    void calc()
    {
        int len = sz(v);
        pref = vi(len + 1);
        suf = vi(len + 1);
        pref[0] = 0;
        for (int i = 0; i < len; ++i) pref[i + 1] = (pref[i] + v[i].val) % mod;
        suf[len] = 0;
        for (int i = len - 1; i >= 0; --i) suf[i] = (suf[i + 1] + v[i].val) % mod;
        val = pref[len];
    }

};



add parse_add();

brackets parse_brackets()
{
    brackets b;
    b.st = pos;
    assert(s[pos] == '(');
    pos++;
    b.val = parse_add().val;
    assert(s[pos] == ')');
    pos++;
    b.en = pos;
    return b;
}

pair<brackets, number> parse_brackets_or_number()
{
    pair<brackets, number> a;
    if (s[pos] == '(')
    {
        a.F = parse_brackets();
        return a;
    }
    a.F = brackets(-1, -1, -1);
    a.S = parse_number();
    return a;
}



mul parse_mul()
{
    mul m;
    m.st = pos;
    while (1)
    {
        m.v.pb(parse_brackets_or_number());
        if (s[pos] == ')' || s[pos] == 0 || s[pos] == '+')
        {
            break;
        }
        assert(s[pos] == '*');
        pos++;
    }
    m.en = pos;
    m.calc();
    return m;
}

int res[N];
vector<pi> q[N];

int u[N];
int uc = 0;

pi POS[N];

int p10[N];



int GIMME_PREF(pair<brackets, number> &a, int k)
{
    if (a.F.val == -1)
    {
        return a.S.pref[k - a.S.st];
    }
    else
    {
        return a.F.val;
    }
}

int GIMME_SUF(pair<brackets, number> &a, int k)
{
    if (a.F.val == -1)
    {
        return a.S.suf[k - a.S.st];
    }
    else
    {
        return a.F.val;
    }
}

int GET_ME_PREF(mul &M, int j, int k)
{
    int X = GIMME_PREF(M.v[j], k);
    return X * (ll)M.pref[j] % mod;
}
int GET_ME_SUF(mul &M, int j, int k)
{
    int X = GIMME_SUF(M.v[j], k);
    return X * (ll)M.suf[j + 1] % mod;
}

add parse_add()
{
    add a;
    a.st = pos;
    while (1)
    {
        a.v.pb(parse_mul());
        if (s[pos] == ')' || s[pos] == 0) break;
        assert(s[pos] == '+');
        pos++;
    }
    a.en = pos;
    a.calc();

    uc++;
    //init positions
    for (int i = 0; i < sz(a.v); ++i)
    {
        for (int j = 0; j < sz(a.v[i].v); ++j)
        {
            pair<brackets, number> z = a.v[i].v[j];
            if (z.F.val == -1)
            {
                //number
                for (int k = z.S.st + 1; k <= z.S.en; ++k)
                {
                    u[k] = uc;
                    POS[k] = {i, j};
                }
            }
            else
            {
                //brackets
                int k = z.F.en;
                u[k] = uc;
                POS[k] = {i, j};
            }
        }
    }

    //run queries
    for (int i = 0; i < sz(a.v); ++i)
    {
        for (int j = 0; j < sz(a.v[i].v); ++j)
        {
            pair<brackets, number> z = a.v[i].v[j];
            if (z.F.val == -1)
            {
                //number
                for (int k = z.S.st; k < z.S.en; ++k)
                {
                    //eprintf("RUN QUERY number %d\n", k);
                    for (pi w : q[k])
                    {
                        int y = w.F;
                        if (u[y] != uc)
                        {
                            res[w.S] = -1;
                            continue;
                        }
                        int i2 = POS[y].F;
                        int j2 = POS[y].S;
                        int k2 = y;

                        if (i == i2)
                        {
                            if (j == j2)
                            {
                                number &E = a.v[i].v[j].S;
                                res[w.S] = (E.pref[y - E.st] - E.pref[k - E.st] * (ll)p10[y - k] % mod + mod) % mod;
                            }
                            else
                            {
                                int L = GIMME_SUF(a.v[i].v[j], k);
                                int M = a.v[i].getMid(j + 1, j2);
                                int R = GIMME_PREF(a.v[i].v[j2], y);
                                res[w.S] = (L * (ll)M % mod * R) % mod;
                            }                                    
                        }
                        else
                        {
                            int L = GET_ME_SUF(a.v[i], j, k);
                            int M = (a.pref[i2] - a.pref[i + 1] + mod) % mod;
                            int R = GET_ME_PREF(a.v[i2], j2, k2);
                            res[w.S] = (L + (ll)M + R) % mod;
                        }
                    }
                }
            }
            else
            {
                //brackets
                int k = z.F.st;
                //eprintf("RUN QUERY brackets %d\n", k);

                // !!! COPYPASTED !!!
                for (pi w : q[k])
                {
                    int y = w.F;
                    if (u[y] != uc)
                    {
                        res[w.S] = -1;
                        continue;
                    }
                    int i2 = POS[y].F;
                    int j2 = POS[y].S;
                    int k2 = y;

                    if (i == i2)
                    {
                        if (j == j2)
                        {
                            brackets &B = a.v[i].v[j].F;
                            res[w.S] = B.val;
                        }
                        else
                        {
                            int L = GIMME_SUF(a.v[i].v[j], k);
                            int M = a.v[i].getMid(j + 1, j2);
                            int R = GIMME_PREF(a.v[i].v[j2], y);
                            res[w.S] = (L * (ll)M % mod * R) % mod;
                        }                                    
                    }
                    else
                    {
                        int L = GET_ME_SUF(a.v[i], j, k);
                        int M = (a.pref[i2] - a.pref[i + 1] + mod) % mod;
                        int R = GET_ME_PREF(a.v[i2], j2, k2);
                        res[w.S] = (L + (ll)M + R) % mod;
                    }
                }
                // !!! COPYPASTED !!!
            
            }
        }
    }
    
    return a;
}        


        

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    p10[0] = 1;
    for (int i = 1; i < N; ++i) p10[i] = p10[i - 1] * 10LL % mod;
    scanf("%s", s);
    int n;
    scanf("%d", &n);
    forn(i, n)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        q[l].pb({r, i});
    }
    forn(i, n) res[i] = -1;
    parse_add();
    //forn(i, n) assert(res[i] != -239);
    forn(i, n) printf("%d\n", res[i]);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}