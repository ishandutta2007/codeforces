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
    vi a(5, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        ++a[s];
    }
    int res = 0;
    for (int i = 4; i >= 3; --i) {
        int j = 4 - i;
        while (a[i] > 0) {          
            --a[i];
            while (j > 0 && a[j] == 0) --j;
            if (j > 0) --a[j];
            ++res;
        }
    }

    int t = a[1] + 2 * a[2];
    res += t / 4;
    if (t % 4) ++res;

    cout << res << "\n";
    return 0;
}