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
    int x, y;
    cin >> x >> y;
    int cur = 0;
    while (1) {
        if (cur == 0) {
            int _x = min(x, 2);
            x -= _x;
            int l = 22 - 10 * _x;
            if (y < l) break;
            y -= l;
        } else {
            if (y >= 22) {
                y -= 22;
            } else if (y >= 12) {
                if (x == 0) break;
                y -= 12;
                --x;
            } else  {
                if (y < 2 || x < 2) break;
                x -= 2;
                y -= 2;
            }
        }
        cur = 1 - cur;
    }
    printf("%s\n", cur ? "Ciel" : "Hanako");
    return 0;
}