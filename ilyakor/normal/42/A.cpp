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
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main()
{
    int n;
    double V;
    cin >> n >> V;
    vector<double> v(n);
    vector<double> w(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    double down = 0.0, up = V;
    for (int it = 0; it < 100; ++it)
    {
        double t = (up + down) * 0.5;
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (w[i] < t * v[i] / sum)
                ok = false;
        if (ok)
            down = t;
        else
            up = t;
    }
    printf("%.10lf\n", (up + down) * 0.5);
    return 0;
}