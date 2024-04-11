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
const int N = 202111;
int a[N];
int b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    int lim = n - 1;
    int root = 0;
    for (int i = 0; i < lim; ++i) {
        int value = a[i + 1];
        while (root * root < i) ++root;

        int clim = min(root, n);
        for (int k = 1; k <= clim; ++k) {
            int parent = i / k;
            if (a[parent] > value) {
                b[k]++;
                b[k+1]--;
            }
        }

        int cur = clim + 1;
        while (cur < n) {
            int parent = i / cur;
            int border;
            if (parent == 0) {
                border = n + 1;
            } else {
                border = (i / parent) + 1;
            }
            if (a[parent] > value) {
                b[cur]++;
                b[border]--;
            }
            cur = border;
        }
    }

    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += b[i];
        printf("%d ", sum);
    }
    cout << endl;

    return 0;
}