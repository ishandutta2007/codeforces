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
    int n, k;
    cin >> n >> k;
    vi b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vi u(n, 0);
    vi res;
    for (int it = 0; it < n; ++it) {
        int opt = -1;
        for (int i = 0; i < n; ++i)
            if (!u[i] && b[i] == 0) {
                opt = i;
                break;
            }
        u[opt] = 1;
        printf("%d ", opt + 1);
        for (int i = 0; i < n; ++i)
            if (!u[i] && opt >= i + k)
                --b[i];
    }
    printf("\n");
    return 0;
}