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

const int N = 2e5 + 20, mod = 998244353;
int n, k, a[N], b[N], pos[N], L[N], R[N];
bool to[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) { 
        cin >> n >> k;
        
        for (int i = 0; i < n; i++) {
            to[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;
        }

        for (int i = 0; i < k; i++) {
            cin >> b[i];
            b[i]--;
            b[i] = pos[b[i]];
            to[b[i]] = 1;
        }

        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }

        int res = 1;
        for (int ii = 0; ii < k; ii++) {
            int i = b[ii];

            int cnt = 0;
            if (L[i] != -1 && !to[L[i]]) {
                cnt++;
            }
            if (R[i] != n && !to[R[i]]) {
                cnt++;
            }

            res = 1ll * res * cnt % mod;

            if (L[i] != -1) R[L[i]] = R[i];
            if (R[i] != n) L[R[i]] = L[i];
        }

        cout << res << '\n';
    }
    
}