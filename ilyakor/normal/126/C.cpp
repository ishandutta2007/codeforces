/*
 * Powered by C++Helper v0.001alpha
*/

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

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vi down(n, 0);
    vi up(n, 0);
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        int l = 0;
        for (int j = n - 1; j > i; --j) {
            int x = v[i][j] - '0';
            if (down[j]) x = 1 - x;
            if (l) x = 1 - x;
            if (x)  {
//                cerr << i << " " << j << "\n";
                down[j] = 1 - down[j];
                l = 1 - l;
                ++res;
            }
        }

        if (l) v[i][i] = '0' + 1 - (v[i][i] - '0');
    }

    for (int i = n - 1; i > 0; --i) {
        int l = 0;
        for (int j = 0; j < i; ++j) {
            int x = v[i][j] - '0';
            if (up[j]) x = 1 - x;
            if (l) x = 1 - x;
            if (x) {
//                cerr << i << " " << j << "\n";
                up[j] = 1 - up[j];
                l = 1 - l;
                ++res;
            }
        }
        if (l) v[i][i] = '0' + 1 - (v[i][i] - '0');
    }
    for (int i = 0; i < n; ++i) {
        int x = v[i][i] - '0';
        if (down[i]) x = 1 - x;
        if (up[i]) x = 1 - x;
        if (x) ++res;
    }
    cout << res << "\n";
    return 0;
}