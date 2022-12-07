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
#include <cassert>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

int c[2];
int n, k;

int got() {
    int whole = (c[1] & 1);
    assert(min(c[0], c[1]) <= (n - k) / 2);
    if (c[0] < c[1]) {
        whole += (n - k) - c[0];
        return whole & 1;
    }
    whole += c[1];
    return whole & 1;
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        c[x & 1]++;
    }

    string FIRST = "Stannis"; // even
    string SECOND = "Daenerys"; // odd

    int steps = n - k;
    if (steps == 0) {
        if (!(c[1] & 1)) {
            cout << SECOND << endl;
        } else {
            cout << FIRST << endl;
        }
        return 0;
    }

    if (steps & 1) { // odd
        int first = (steps + 1) / 2;
        int second = steps - first;

        if (min(c[0], c[1]) > second) {
            cout << FIRST << endl;
            return 0;
        }

        if (got() == 1) cout << FIRST << endl;
        else cout << SECOND << endl;
    } else {
        int first = steps / 2;

        if (min(c[0], c[1]) > first) {
            cout << SECOND << endl;
            return 0;
        }

        if (got() == 1) cout << FIRST << endl;
        else cout << SECOND << endl;
    }

    return 0;
}