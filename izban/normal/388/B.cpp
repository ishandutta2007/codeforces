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


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> e[maxn];
int d[maxn];
char c[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int k;
    while (cin >> k) {
        for (int i = 0; i < maxn; i++) e[i].clear();
        
        int cur = 1, nw = 3;
        while (k > 1) {
            if (k % 2 == 0) {
                int a1 = nw++;
                int a2 = nw++;
                int a3 = nw++;
                d[a1] = d[cur] + 1;
                d[a2] = d[cur] + 1;
                d[a3] = d[cur] + 2;
                e[cur].push_back(a1);
                e[cur].push_back(a2);
                e[a1].push_back(a3);
                e[a2].push_back(a3);
                cur = a3;
                k /= 2;
            } else {
                int a1 = nw++;
                e[cur].push_back(a1);
                d[a1] = d[cur] + 1;
                k--;
            }
        }
        e[cur].push_back(2);
        d[2] = d[cur] + 1;
        
        for (int i = 1; i < nw; i++) {
            if (e[i].empty() && i != 2) {
                if (d[i] + 1 < d[2]) {
                    int a1 = nw++;
                    d[a1] = d[i] + 1;
                    e[i].push_back(a1);
                } else e[i].push_back(2);
            }
        }
        
        for (int i = 1; i < nw; i++) for (int j = 1; j < nw; j++) c[i][j] = 'N';
        for (int i = 1; i < nw; i++) for (int j = 0; j < e[i].size(); j++) c[i][e[i][j]] = c[e[i][j]][i] = 'Y';
        
        cout << nw - 1 << endl;
        for (int i = 1; i < nw; i++) {
            for (int j = 1; j < nw; j++) {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    
	return 0;
}