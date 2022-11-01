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
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

void read(int& x) {
    scanf("%d", &x);
}
 
void read(int& x, int& y) {
    scanf("%d %d", &x, &y);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, L;
    read(n, L);
    vector<int> f, s, a, b;

    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        read(x);

        if (i != 0) {
            f.pb(x - a.back());
            sum1 += x - a.back();
        }
        a.pb(x);
    }
    f.pb(L - sum1);

    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        read(x);

        if (i != 0) {
            s.pb(x - b.back());
            sum2 += x - b.back();
        }
        b.pb(x);
    }
    s.pb(L - sum2);
    
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if (f == s) ok = 1;
        int x = f.front();
        f.erase(f.begin());
        f.pb(x);
    }
    puts(ok ? "YES" : "NO");
    return 0;
}