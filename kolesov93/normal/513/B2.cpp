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

const int N = 111;
int a[N];

int main() {
    int n; cin >> n;
    ll m; cin >> m;
    int l = 0, r = n - 1;
    
    --m;
    for (int i = 0; i < n; ++i) {
        int left = n - i - 2;
        ll half = 1LL << left;
        
        if (m < half) {
            a[l++] = i;
        } else {
            m -= half;
            a[r--] = i;
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] + 1 << ' ';
    cout << endl;


    return 0;
}