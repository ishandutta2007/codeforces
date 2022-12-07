#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

const int N = 111;
char w[N][N];

int main() {
    set<char> good = {'f', 'a', 'c', 'e'};
    int n, m;
    cin >> n >> m;
    scanf("\n");
    for (int i = 0; i < n; ++i)  {
        gets(w[i]);
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j + 1 < m; ++j) {
            set<char> a;
            a.insert(w[i][j]);
            a.insert(w[i+1][j]);
            a.insert(w[i][j+1]);
            a.insert(w[i+1][j+1]);
            if (a == good) ++ans;
        }

    cout << ans << endl;

    return 0;
}