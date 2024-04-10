#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
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
    cin >> n;
    if (n == 2)
    {
        cout << "-1\n";
        return 0;
    }
    vi res(n, 1);
    for (int i = 1; i < n; ++i)
        res[i] *= 2;
    for (int i = 0; i < n - 1; ++i)
        res[i] *= 3;
    res[0] *= 5, res[n - 1] *= 5;
    int cur = 7;
    for (int i = 0; i < n; ++i)
    {
        res[i] *= cur;
        while (1)
        {
            ++cur;
            bool ok = true;
            for (int j = 2; j * j <= cur; ++j)
                if (cur % j == 0) {
                    ok = false;
                    break;
                }
            if (ok) break;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", res[i]);
    return 0;
}