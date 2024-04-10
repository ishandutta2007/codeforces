#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int T;

const int N = 2e5 + 20;
int n, a[N], h[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        h[0] = 0;
        int par = 0, cur = 1;
        bool fl = 1;

        for (int i = 1; i < n; i++) {
            if (i != 1 && a[i] < a[i - 1]) par++;
            h[i] = h[par] + 1;
        }
    
        cout << h[n - 1] << '\n';
        
    }
}