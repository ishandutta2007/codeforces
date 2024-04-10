#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1000000;

int X[maxn], V[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &X[i], &V[i]);
    }
    double down = 0.0, up = 1E15;
    for (int it = 0; it < 90; it++)
    {
        double t = (up + down) * 0.5;
        bool ok = false;
        double mx = -1E100, tx;
        for (int i = 0; i < n; i++)
        {
            tx = X[i] + V[i] * t;
            if (V[i] > 0)
            {
                if (tx > mx)
                    mx = tx;
            }
            else
            {
                if (tx <= mx)
                {
                    ok = true;
                    break;
                }
            }
        }
        if (ok)
            up = t;
        else
            down = t;
    }
    double res = (up + down) * 0.5;
    if (res > (1E12))
        cout << "-1\n";
    else
        printf("%.20lf\n", res);
    return 0;
}