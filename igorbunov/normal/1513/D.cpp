#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

//#pragma GCC_OPTIMIZE("ofast")
using namespace std;
 

#define int long long
bool comp(int a, int b) {
    return (a % 2) < (b % 2);
}

int mod = 1000000007LL;


void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    vector<pair<int, int>> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr1[i].first = arr[i];
        arr1[i].second = i;
    }
    sort(arr1.begin(), arr1.end());
    vector<int> was(n, p);
    for (int i = 0; i < n; i++) {
        if (arr1[i].first > p) {
            break;
        }
        int val = arr1[i].first;
        int ind = arr1[i].second;
        //cout << ind << " ";
        int l = ind;
        bool kek = false;
        while (l != 0 && arr[l - 1] % val == 0) {
            l--;
            if (arr[l] == val) {
                kek = true;
                break;
            }
        }
        if (kek) {
            continue;
        }
        int r = ind;
        while (r != n - 1 && arr[r + 1] % val == 0) {
            r++;
        }
        
        for (int j = l; j < r; j++) {
            was[j] = min(was[j], val);
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += was[i];
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
    }
}