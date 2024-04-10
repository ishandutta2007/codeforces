#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

const int maxn = 1500000;

int a[maxn * 2];
int R[maxn * 2];
int RR[maxn * 2];
int D[maxn * 2];

int main()
{
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
        mx = max(mx, a[i]);
    }
    int64 res = 0;
    int64 mcnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == mx) mcnt++;
    res -= sqr(mcnt);
    if (mcnt == 1)
    {
        int mxx = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != mx)
                mxx = max(mxx, a[i]);
        }
        if (mxx != 0)
        {
            int tt = 0;
            for (int i = 0; i < n; i++)
                if (a[i] == mxx)
                    tt++;
            res -= tt;
        }
    }
    a[2 * n] = 2000000000;
    D[2 * n] = 0;
    D[2 * n - 1] = 1;
    R[2 * n - 1] = 2 * n;
    int mc = 0;
    for (int i = 2 * n - 2; i >= 0; i--)
    {
        {
            int r = i + 1;
            while (a[r] <= a[i])
                r = R[r];
            R[i] = r;
        }
        {
            int r = i + 1;
            while (a[r] < a[i])
                r = R[r];
            RR[i] = r;
            D[i] = a[r] == a[i] ? D[r] : 0;
            D[i]++;
        }
        if (i < n)
        {
            if (a[i] == mx) mc++;
            int cur = i + 1;
            while (cur < 2 * n)
            {
                if (a[cur] <= a[i])
                    res += D[cur];
                else
                    res++;
                if (a[cur] > a[i]) break;
                cur = R[cur];
            }
        }
    }   
    cout << res << "\n";
    return 0;
}