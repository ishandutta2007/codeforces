#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, x;
vector<pair<int, int> > a[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pair<int, int> o;
        cin >> o.first >> o.second;
        a[t].push_back(o);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    vector<char> eaten[2];
    eaten[0].assign(a[0].size(), 0);
    eaten[1].assign(a[1].size(), 0);
    
    int ox = x;
    int ans = 0;
    for (int oo = 0; oo < 2; oo++) {
        eaten[0].assign(a[0].size(), 0);
        eaten[1].assign(a[0].size(), 0);
        int res = 0;
        for (int i = 0; ; i++) {
            int j = -1;
            for (int k = 0; k < a[i % 2].size(); k++) {
                if (a[i % 2][k].first <= x && !eaten[i % 2][k] && (j == -1 || a[i % 2][k].second > a[i % 2][j].second)) {
                    j = k;
                }
            }
            if (j == -1) break;
            eaten[i % 2][j] = 1;
            x += a[i % 2][j].second;
            res++;
        }
        ans = max(ans, res);
        x = ox;
        swap(a[0], a[1]);
    }    
    cout << ans << endl;
	return 0;
}