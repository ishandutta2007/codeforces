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
//#include <cmath>

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

const int maxn = 12 * 1000 * 1000;

char ts[maxn];
int z[maxn];
int n;

int d[maxn];

int main()
{
    scanf("%s", ts);
    n = strlen(ts);
    ts[n] = '#';
    for (int i = 0; i < n; i++)
        ts[n + i + 1] = ts[n - i - 1];
    ts[2 * n + 1] = 0;
    int l = 0, r = 0;
    int len = 2 * n + 1;
    for (int i = 1; i < len; i++)
    {
        if (z[i - l] + i <= r)
            z[i] = z[i - l];
        else
        {
            l = i;
            if (i > r) r = i;
            for (z[i] = r - i; r < len; r++, z[i]++)
                if (ts[r] != ts[z[i]])
                    break;
            r--;
        }
    }
    d[0] = 1;
    int64 res = 1;
    for (int i = 1; i < n; i++)
    {
        int ind = 2 * n - i;
        //cerr << i << ": " << z[ind] << "\n";
        if (z[ind] >= i + 1)
        {
            d[i] = d[(i + 1) / 2 - 1] + 1;
        }
        else
            d[i] = 0;
        res += d[i];
    }
    cout << res << "\n";
    return 0;
}