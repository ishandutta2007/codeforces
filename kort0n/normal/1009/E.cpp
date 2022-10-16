#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const long long p = 998244353;

int main() {
    int n;
    cin >> n;
    long long beki[1000010];
    beki[0] = 1;
    for(int i = 1; i <= (n - 1); i++){
        beki[i] = (beki[i - 1] * 2) % p;
    }
    long long a[1000010];
    for(int i = 1; i <= n; i++){
        scanf("%I64d", &a[i]);
    }
    long long cost[1000010];
    cost[1] = 1;
    for(long long i = 2; i <= n; i++){
        cost[i] = (beki[i - 1] + (i - 1) * beki[i - 2]) % p;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + a[i] * cost[n + 1 - i]) % p;
    }
    cout << ans << endl;
    return 0;
}