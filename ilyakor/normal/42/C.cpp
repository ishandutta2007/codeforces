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
    vi v(4), target(4, 1);
    for (int i = 0; i < 4; ++i)
        cin >> v[i];
    while (v != target)
    {
        int x;
        for (int i = 0; i < 4; ++i)
            if (v[i] != 1)
            {
                x = i;
                break;
            }
        if (v[x] == 2 && v[0] + v[1] + v[2] + v[3] == 1 + 1 + 1 + 2)
        {
            printf("+%d\n", x + 1);
            ++v[x], ++v[(x + 1) % 4];
            printf("+%d\n", (x + 3) % 4 + 1);
            ++v[x], ++v[(x + 3) % 4];
            printf("/%d\n", (x + 3) % 4 + 1);
            v[x] /= 2, v[(x + 3) % 4] /= 2;
            printf("/%d\n", x + 1);
            v[x] /= 2, v[(x + 1) % 4] /= 2;
            continue;
        }
        int y = (x + 1) % 4;
        if (v[x] % 2 != v[y] % 2)
        {
            if (v[x] % 2 == 0)
            {
                printf("+%d\n", y + 1);
                ++v[y];
                ++v[(y + 1) % 4];
            }
            else
            {
                printf("+%d\n", (x + 3) % 4 + 1);
                ++v[x];
                ++v[(x + 3) % 4];
            }
        }
        if (v[x] % 2)
        {
            printf("+%d\n", x + 1);
            ++v[x];
            ++v[y];
        }
        v[x] /= 2;
        v[y] /= 2;
        printf("/%d\n", x + 1);
    }
    return 0;
}