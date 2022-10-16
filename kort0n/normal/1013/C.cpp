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

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    vector<long long> a(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = (a[2 * n - 1] - a[n]) * (a[n - 1] - a[0]);
    for(int i = 0; i <= n; i++){
        long long dy = a[2 * n - 1] - a[0];
        long long dx = a[i + n - 1] - a[i];
        ans = min(ans, dx * dy);
    }
    cout << ans << endl;
}