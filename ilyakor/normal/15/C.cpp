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

int64 get(int64 x)
{
    if (x <= 0) return 0;
    int64 p = 1;
    while (p * 2LL <= x) p *= 2LL;
    int64 res = 0;
    if (p == 1) res = 0;
    else if (p == 2) res = 1;
    else res = 0;
    x -= p;
    if ((x + 1LL) % 2LL == 1LL)
        res ^= p;
    res ^= get(x);
    return res;
}


int main()
{
    /*int64 tmp = 0;
    for (int i = 0; i < 10000000; i++)
    {
        tmp ^= i;
        if (get(i) != tmp)
        {
            cerr << "botva " << i << ": " << get(i) << " " << tmp << "\n";
            return 0;
        }
    }*/
    //cout << (get(5757575757575757LL) ^ get(5757575757575756LL)) << "\n";;
    int n;
    cin >> n;
    int64 res = 0;
    for (int i = 0; i < n; i++)
    {
        int64 m, x;
        //cin >> m >> x;
        cin >> x >> m;
        assert(x >= 1);
        assert(m >= 1);
        res ^= get(x - 1) ^ get(x + m - 1);
    }
    if (res != 0LL) printf("tolik\n");
    else printf("bolik\n");
    return 0;
}