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

#define int ll

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int mod = 1e6 + 3, MAX = mod + 10;
int n, k;

int p2[MAX];

void pre () {
    for (int i = p2[0] = 1; i < MAX; i++)
        p2[i] = p2[i - 1] * 2 % mod;
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    pre();

    cin >> n >> k;

    if (n <= 60 && (1ll << n) < k) return cout << "1 1\n", 0; 

    k--;

    int tot = 0;

    for (int i = 1; i <= 60; i++) {
        tot += k / (1ll << i);
    }

    int A = 1;
  
    int P = ((((n % (mod - 1)) * (k % (mod - 1)) - tot) % (mod - 1)) + mod - 1) % (mod - 1);

    int B = p2[P];

    if (k >= mod + 10) A = 0;
    else {
        int val = p2[n % (mod - 1)];
        for (int i = 1; i <= k; i++) 
            A = 1ll * A * (val - i) % mod;
        
        A = 1ll * A * p2[1ll * (mod - 2) * tot % (mod - 1)] % mod;
    }

    A = (B - A + mod) % mod;

    cout << A << ' ' << B << '\n';
    
}