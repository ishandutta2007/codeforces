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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i].first = arr[i + 1] - arr[i];
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());
    vector<bool> used(n);
    for (int i = 0; i < k - 1; i++) {
        used[b[i].second] = 1;
    }
    int now = 0;
    for (int i = 0; i < n - 1; i++) {
        if (used[i]) {
            now++;
        } else {
            now += arr[i + 1] - arr[i];
        }
    }
    cout << now + 1;
}