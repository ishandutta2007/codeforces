#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const ld PI = acos(-1.);

const int N = 8;
int a[N];



int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector< vector<int> > b;
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    int m; cin >> m;
    int best = -1;
    do {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int mn = a[i] + 1;
            for (int j = i; j < n; ++j) {
                ans += mn;
                if (j + 1 < n)
                mn = min(mn, a[j + 1] + 1);
            }
        }

        if (best < ans) {
            best = ans;
            b.clear();
        }
        if (best == ans) {
            b.push_back(a);
        }
    } while (next_permutation(a.begin(), a.end()));

    for (int i = 0; i < n; ++i) cout << b[m - 1][i] + 1 << " ";
    cout << endl;

    return 0;
}