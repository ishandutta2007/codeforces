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
#define pd pair<double, double>

double eps = 1e-7;


signed main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (arr.size() > 1) {
            if (arr[arr.size() - 1] == arr[arr.size() - 2] && arr[arr.size() - 1] == a) {
                //continue;
            }
        }
        arr.push_back(a);
    }
    n = arr.size();
    vector <vector<bool>> d(n, vector<bool>(5, 0));
    vector <vector<int>> p(n, vector<int>(5, -1));
    d[0][0] = 1;
    d[0][1] = 1;
    d[0][2] = 1;
    d[0][3] = 1;
    d[0][4] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] > arr[i - 1]) {
                for (int k = 0; k < j; k++) {
                    if (d[i - 1][k]) {
                        p[i][j] = k;
                    }
                    d[i][j] = d[i][j] || d[i - 1][k];
                }
            }
            if (arr[i] == arr[i - 1]) {
                for (int k = 0; k < 5; k++) {
                    if (k == j) {
                        continue;
                    }
                    if (d[i - 1][k]) {
                        p[i][j] = k;
                    }
                    d[i][j] = d[i][j] || d[i - 1][k];
                }
            }
            if (arr[i] < arr[i - 1]) {
                for (int k = j + 1; k < 5; k++) {
                    if (d[i - 1][k]) {
                        p[i][j] = k;
                    }
                    d[i][j] = d[i][j] || d[i - 1][k];
                }
            }
        }
    }
    int ind = n - 1;
    //xcout << ind << endl;
    vector<bool> can(5, 1);
    vector<int> ans;
    int now = -1;
    for (int i = 0; i < 5; i++) {
        if (d[ind][i]) {
            now = i;
        }
    }
    if (now == -1) {
        cout << -1;
        return 0;
    }
    while (ind >= 0) {
        ans.push_back(now);
        now = p[ind][now];
        ind--;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1<< " ";
    }
    return 0;
}