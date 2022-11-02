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
    string s;
    cin >> s;
    vi res(n, 1);
    while (1) {
        bool ch = false;
        for (int i = 1; i < n; ++i) {
            if (i < 1) continue;
            if (s[i - 1] == 'L') {
                if (res[i - 1] <= res[i])
                    res[i - 1] = res[i] + 1, i -= 2, ch = true;
            } else if (s[i - 1] == 'R') {
                if (res[i - 1] >= res[i])
                    res[i] = res[i - 1] + 1, ch = true;
            } else {
                int x = max(res[i], res[i - 1]);
                if (res[i] != x || res[i - 1] != x)
                    res[i] = res[i - 1] = x, ch = true;
            }
        }
        if (!ch) break;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}