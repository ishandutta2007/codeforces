#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
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

using namespace std;

#define data NE_data
#define rank NE_rank
#define time NE_time
#define endl '\n'

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr1(n);
    if (a == b) {
        if (a * 2 + 1 > n - 1) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < b; i++) {
            arr1[i * 2 + 1] = 1;
        }
    }
    if (abs(a - b) > 1) {
        cout << -1 << endl;
        return;
    }

    if (a == b + 1) {
        if (a * 2 > n - 1) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < a; i++) {
            arr1[i * 2] = 1;
        }
    }

    if (a + 1 == b) {
        if (b * 2 > n - 1) {
            cout << -1 << endl;
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            arr1[i] = 1;
        }

        for (int i = 0; i < b; i++) {
            arr1[i * 2] = 0;
        }
    }

    /*cout << "! " << a << " " << b << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl << endl;*/



    int l = 1;
    int r = n;


    if (arr1[0] == 1) {
        cout << l << " ";
        l++;
    } else {
        cout << r << " ";
        r--;
    }

    for (int i = 0; i < n - 1; i++) {
        if ((arr1[i] == 1) ^ (i != n - 2 && arr1[i] == arr1[i + 1])) {
            cout << r << " ";
            r--;
        } else {
            cout << l << " ";
            l++;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}