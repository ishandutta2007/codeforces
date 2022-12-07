#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int N = 1111222;
int a[N];
int n, m;


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if (i == 0) {
            a[m++] = x;
        } else {
            if (x > a[m - 1]) {
                a[m++] = x;
                continue;
            }

            int l = 0, r = m - 1;
            while (l < r) {
                int center = (l + r) >> 1;
                if (a[center] < x) l = center + 1;
                else r = center;
            }
            a[l] = x; 
        }
    }

    cout << m << endl;
    
    return 0;
}