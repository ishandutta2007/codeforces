#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 1e5 + 5;
const int inf = 1e8;
const double eps = 1e-8;
const int base = 1073676287;

void read(int& x) {
    scanf("%d", &x);
}
 
void read(int& x, int& y) {
    scanf("%d %d", &x, &y);
}

int a[maxn], c[maxn], b[maxn], p[maxn];

int main() {
    int n, l, r;
    read(n);
    read(l, r);
    
    int prev = 0;
    for (int i = 0; i < n; i++)
        read(a[i]);
    for (int i = 0; i < n; i++) {
        read(c[i]);
        p[c[i] - 1] = i;
    }

    for (int i = 0; i < n; i++) {
        int x = p[i];
        if (i == 0) {
            b[x] = l;
        } else {
            b[x] = max(l, prev + a[x] + 1);
            if (b[x] > r)
                return cout << -1, 0;
        }
        prev = b[x] - a[x];
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    return 0;
}