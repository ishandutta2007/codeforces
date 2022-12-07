#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

const int N = 5555;
char a[N], b[N];
int n, m;
ll f[N][N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%s", a);
    scanf("%s", b);
    n = strlen(a);
    m = strlen(b);
    
    for (int j = 0; j < m; ++j)
        if (a[0] == b[j]) f[0][j] = 1;
    
    for (int i = 1; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) { 
                f[i][j] += 1;
                f[i][j] = (f[i][j] + sum) % mod;
            }
            if (b[j] == a[i - 1]) sum += f[i - 1][j];
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
            ans += f[i][j];
            //if (f[i][j] != 0) cout << i << " " << j << " " << f[i][j] << endl;
        }
        ans %= mod;
    }
    
    cout << ans << endl;
    
    return 0;
}