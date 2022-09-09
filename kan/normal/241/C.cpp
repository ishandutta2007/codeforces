#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 105;
const int length = 100000;
const int h = 100;
const double eps = 1e-7;

int point[maxn], l[maxn], r[maxn];
bool topm[maxn];
bool was[maxn];
char wh[3];
int n, hs, hf;

int can(double t, int hs, bool extop)
{
//     cout << "can " << t << ' ' << hs << ' ' << (extop ? "true" : "false") << endl;
    for (int i = 0; i < n; i++) was[i] = false;
    double x = hs * t;
    bool wh = false;
    int ans = 0;
    while (x < length)
    {
//         cout << x << ' ' << (wh ? "true" : "false") << endl;
        bool wasm = false;
        for (int i = 0; i < n; i++) if ((topm[i] ^ extop ^ wh) == false && l[i] <= x + eps && r[i] >= x - eps)
        {
            if (was[i]) return 0;
            was[i] = true;
            ans += point[i];
            wasm = true;
        }
        if (!wasm) return 0;
        x += t * h;
        wh = !wh;
    }
//     cout << ans << endl;
    return ans;
}

int main()
{
    scanf("%d%d%d", &hs, &hf, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%d%d", &point[i], wh, &l[i], &r[i]);
        if (wh[0] == 'T') topm[i] = true;
        else topm[i] = false;
    }
    int answer = 0;
    for (int i = 1; i <= n; i += 2)
    {
        int lenh = hs + hf + h * (i - 1);
        double t = (double)length / lenh;
        answer = max(answer, can(t, hs, false));
        lenh = (h - hs) + (h - hf) + h * (i - 1);
        t = (double)length / lenh;
        answer = max(answer, can(t, h - hs, true));
    }
    for (int i = 2; i <= n; i += 2)
    {
        int lenh = hs + (h - hf) + h * (i - 1);
        double t = (double)length / lenh;
        answer = max(answer, can(t, hs, false));
        lenh = (h - hs) + hf + h * (i - 1);
        t = (double)length / lenh;
        answer = max(answer, can(t, h - hs, true));
    }
    cout << answer << endl;
    return 0;
}