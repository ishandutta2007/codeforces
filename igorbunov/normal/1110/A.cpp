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
    bool now = 0;
    int b, k;
    cin >> b >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());
    bool c = b % 2;
    now = arr[0] % 2;
    for (int i = 1; i < k; i++) {
        if (c && arr[i] % 2) {
            now ^= 1;
        }
    }
    if (now == 0) {
        cout << "even";
    } else {
        cout << "odd";
    }
}