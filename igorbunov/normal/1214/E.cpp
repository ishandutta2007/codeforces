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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

vector<int> d;
bool cmp(int i, int j) {
    return d[i] < d[j];
}

signed main() {
    int n;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
        ind[i] = i;
    }
    sort(ind.rbegin(), ind.rend(), cmp);
    vector<int> arr1(n);
    vector<vector<int>> arr2(n);
    for (int i = 0; i < n; i++) {
        arr1[i] = 2 * ind[i];
        if (i + d[ind[i]] >= (int)arr1.size()) {
            arr1.push_back(2 * ind[i] + 1);
            arr2.push_back(vector<int>(0));
        } else {
            arr2[i + d[ind[i]] - 1].push_back(2 * ind[i] + 1);
        }
    }
    for (int i = 0; i + 1 < (int)arr1.size(); i++) {
        cout << arr1[i] + 1 << " " << arr1[i + 1] + 1 << endl;
    }

    for (int i = 0; i < (int)arr1.size(); i++) {
        for (auto x : arr2[i]) {
            cout << arr1[i] + 1 << " " << x + 1 << endl;
        }
    }
}