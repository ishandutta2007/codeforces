#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
 
    vector<int> arr(n);
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    sort(arr.begin(), arr.end());
 
    vector<long long> ans(n);
 
    long long now = 0;
 
    for (int k = 0; k < n; ++k) {
        now += arr[k];
        ans[k] = now;
 
        if (k >= m) {
            ans[k] += ans[k - m];
        }
 
        cout << ans[k] << " ";
    }
}