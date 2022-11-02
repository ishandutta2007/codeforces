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
    int cur = 0;
    vi v(n, 0);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++cur;
            cur %= n;
            while (v[cur])
                cur = (cur + 1) % n;
        }
        //v[cur] = 1;
        printf("%d ", cur + 1);
    }
    printf("\n");
    return 0;
}