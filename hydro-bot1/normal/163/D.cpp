// Hydro submission #62f2123ada6f99552b33eec6@1660031546566
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>
#include<algorithm>

using i64 = long long;
using namespace std;

namespace IO
{
    int f, c;

    template<typename T> inline void _Read(T &k)
    {
        k = 0, f = 1, c = getchar();
        while(!isdigit(c))
        {
            if(c == '-') f = -1;
            c = getchar();
        }
        while(isdigit(c))
        {
            k = (k << 3) + (k << 1) + c - '0';
            c = getchar();
        }
        return k *= f, void();
    }

    template<typename T> inline void _Write(T k)
    {
        if(k < 0) putchar('-'), k = -k;
        if(k > 9) _Write(k / 10);
        return putchar(k % 10 + '0'), void();
    }

    inline int Read32() { int k; _Read(k); return k; }
    inline i64 Read64() { i64 k; _Read(k); return k; }
    inline void Write32(int k, char ed = '\n') { return _Write(k), putchar(ed), void(); }
    inline void Write64(i64 k, char ed = '\n') { return _Write(k), putchar(ed), void(); }
}

using IO :: Read32;
using IO :: Read64;
using IO :: Write32;
using IO :: Write64;

namespace Program
{
    const int MAXN = 21;
    const long double EPS = 1e-8;
    const i64 INF = 0x7FFFFFFFFFFFFFFF;

    int t, k, q[MAXN];
    i64 V, p[MAXN], lima, limb, S, A, B, C;

    inline void Get_B(int now, i64 a, i64 b)
    {
        if(b > limb) return;
        if(now == k + 1)
        {
            if(a > b) return;
            i64 c = V / a / b, s = (a * b + b * c + a * c) * 2;
            if(s < S) S = s, A = a, B = b, C = c;
            return;
        }
        if(q[now]) --q[now], Get_B(now, a, b * p[now]), ++q[now];
        Get_B(now + 1, a, b);
        return;
    }

    inline void Get_A(int now, i64 a)
    {
        if(a > lima) return;
        if(now == k + 1)
        {
            i64 r = (i64)(floorl(sqrtl(V / a) + EPS));
            if((V / a + a * r * 2) * 2 >= S) return;
            limb = r;
            return Get_B(1, a, 1);
        }
        if(q[now]) --q[now], Get_A(now, a * p[now]), ++q[now];
        Get_A(now + 1, a);
        return;
    }

    inline int Run()
    {
        t = Read32();
        while(t--)
        {
            k = Read32(), V = 1;
            for(register int i = 1; i <= k; i++)
            {
                p[i] = Read64(), q[i] = Read32();
                for(register int j = 1; j <= q[i]; j++) V *= p[i];
            }
            lima = (i64)(floorl(powl(V, 1.0 / 3.0) + EPS)), S = INF;
            Get_A(1, 1), Write64(S, ' '), Write64(A, ' '), Write64(B, ' '), Write64(C);   
        }
        return 0;
    }
}

int main() { return Program :: Run(); }