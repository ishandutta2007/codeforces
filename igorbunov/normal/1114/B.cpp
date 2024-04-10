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
using namespace std;
 
#define int long long
#define endl '\n'

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> arr(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.rbegin(), arr.rend());
    vector<int> p;
    int ans = 0;
    for (int i = 0; i < m * k; i++) {
        ans += arr[i].first;
        p.push_back(arr[i].second);
    }
    cout << ans << endl;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size() - 1; i++) {
        if (i % m == m - 1) {
            cout << p[i] + 1 << " "; 
        }
    }
}