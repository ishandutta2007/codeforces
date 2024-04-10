// Hydro submission #62f2124c3f8efa55416cb44e@1660031565015
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<map>

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
    const int MAXN = 31;

    int n, k, lim;
    i64 s, a[MAXN], fac[MAXN], ans;
    map<pair<int, i64>, int> lm, rm;

    inline void DFS_Left(int now, int cnt, i64 sum)
    {
        if(now == (n >> 1) + 1)
        {
            pair<int, i64> key = make_pair(cnt, sum);
            if(!lm.count(key)) lm.insert(make_pair(key, 0));
            return ++lm[key], void();
        }
        DFS_Left(now + 1, cnt, sum);
        if(sum + a[now] <= s) DFS_Left(now + 1, cnt, sum + a[now]);
        if(a[now] <= lim && cnt + 1 <= k && sum + fac[a[now]] <= s) DFS_Left(now + 1, cnt + 1, sum + fac[a[now]]);
        return;
    }

    inline void DFS_Right(int now, int cnt, i64 sum)
    {
        if(now == (n >> 1))
        {
            pair<int, i64> key = make_pair(cnt, sum);
            if(!rm.count(key)) rm.insert(make_pair(key, 0));
            return ++rm[key], void();
        }
        DFS_Right(now - 1, cnt, sum);
        if(sum + a[now] <= s) DFS_Right(now - 1, cnt, sum + a[now]);
        if(a[now] <= lim && cnt + 1 <= k && sum + fac[a[now]] <= s) DFS_Right(now - 1, cnt + 1, sum + fac[a[now]]);
        return;
    }

    inline int Run()
    {
        n = Read32(), k = Read32(), s = Read64();
        for(register int i = 1; i <= n; i++) a[i] = Read64();
        fac[0] = fac[1] = 1;
        while(fac[lim + 1] <= s) ++lim, fac[lim + 1] = fac[lim] * (lim + 1);
        if(n == 1)
        {
            if(a[n] == s) ++ans;
            if(a[n] <= lim && fac[a[n]] == s) ++ans;
            Write64(ans);
            return 0;
        }
        lm.clear(), rm.clear();
        DFS_Left(1, 0, 0), DFS_Right(n, 0, 0);
        for(auto it : lm)
        {
            int cnt = it.first.first, res = it.second; i64 sum = it.first.second;
            if(res) for(register int i = 0; i + cnt <= k; i++) ans += 1LL * res * rm[make_pair(i, s - sum)];
        }
        Write64(ans);
        return 0;
    }
}

int main() { return Program :: Run(); }