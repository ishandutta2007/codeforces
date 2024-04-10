#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


struct Event
{
    long long pos, val;

    Event() : pos(), val() {}
    Event(long long _pos, long long _val) : pos(_pos), val(_val) {}

    bool operator < (const Event &A) const
    {
        if (pos != A.pos)
            return pos < A.pos;
        return val < A.val;
    }
};

const int N = (int) 2e5 + 100;
long long p[N], pos[N];
long long x[N];


int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        pos[i] = i * 100;
        scanf("%lld", &p[i]);
    }
    for (int i = 0; i < m; i++)
        scanf("%lld", &x[i]);

    x[m++] = -(long long) 1e10;
    x[m++] = (long long) 1e10;
    sort(x, x + m);

    int ptr = 0;
    vector <Event> ev;
    long long ans = 0;
    for (int it = 0; it + 1 < m; it++)
    {
        ev.clear();
        long long lx = x[it], rx = x[it + 1];
        //eprintf("%lld .. %lld\n", lx, rx);
        while (ptr < n && pos[ptr] < rx)
        {
            if (pos[ptr] != lx && pos[ptr] != rx)
            {
                ev.push_back(Event(2 * pos[ptr] - rx, p[ptr]));
                ev.push_back(Event(2 * pos[ptr] - lx, -p[ptr]));
            }
            ptr++;
        }
        sort(ev.begin(), ev.end());
        long long cnt = 0;
        for (auto &e : ev)
        {
            //eprintf("%lld : %lld\n", e.pos, e.val);
            cnt += e.val;
            ans = max(ans, cnt);
        }
    }
    printf("%lld\n", ans);


	return 0;
}