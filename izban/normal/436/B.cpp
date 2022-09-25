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

int n, m, k;
string a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> m >> k) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> ans(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'L') {
                    if (j - i >= 0) {
                        ans[j - i]++;   
                    }
                }
                if (a[i][j] == 'R') {
                    if (j + i <= m - 1) {
                        ans[j + i]++;   
                    }                
                }
                if (a[i][j] == 'U') {
                    if (i % 2 == 0) {
                        ans[j]++;   
                    }                
                }
                if (a[i][j] == 'D') {
                
                }
            }
        }
        for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i + 1 == m];
    }
    
	return 0;
}