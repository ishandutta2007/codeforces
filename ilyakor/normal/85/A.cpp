#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

char a[4][1000];

int main() {
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    int l = 0, r = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        a[0][i] = a[0][i + 1] = 'x' + (i % 4 == 0 ? 0 : -2);
        a[1][i] = a[1][i + 1] = 'y' + (i % 4 == 0 ? 0 : -2);
        l = i + 2;
    }
    a[2][0] = a[3][0] = 'z';
    for (int i = 1; i + 1 < n; i += 2) {
        a[2][i] = a[2][i + 1] = 'p' + ((i - 1) % 4 == 0 ? 0 : -2);
        a[3][i] = a[3][i + 1] = 'q' + ((i - 1) % 4 == 0 ? 0 : -2);
        r = i + 2;
    }
    for (int i = l; i < n; ++i) {
        a[0][i] = a[1][i] = 'a' + (i % 2 == 0 ? 0 : 2);
    }
    for (int i = r; i < n; ++i) {
        a[2][i] = a[3][i] = 'b' + (i % 2 == 0 ? 0 : 2);
    }
    for (int i = 0; i < 4; ++i)
        printf("%s\n", a[i]);
    return 0;
}