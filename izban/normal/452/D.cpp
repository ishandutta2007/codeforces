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

void print(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }   
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int k, n[4], t[4];
    while (cin >> k) {
        for (int i = 1; i < 4; i++) cin >> n[i];
        for (int i = 1; i < 4; i++) cin >> t[i];

        queue<int> q[4];
        for (int i = 1; i < 4; i++) for (int j = 0; j < n[i]; j++) q[i].push(0);
        
        int cur = 0;
        int ans = 0;
        while (k) {
            //for (int i = 1; i < 4; i++) print(q[i]);
            if (q[1].front() <= cur && q[2].front() <= cur + t[1] && q[3].front() <= cur + t[1] + t[2]) {
                ans = max(ans, cur + t[1] + t[2] + t[3]);
                q[1].push(cur + t[1]);
                q[2].push(cur + t[1] + t[2]);
                q[3].push(cur + t[1] + t[2] + t[3]);
                
                q[1].pop();
                q[2].pop();
                q[3].pop();
                k--;
            } else {
                cur++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}