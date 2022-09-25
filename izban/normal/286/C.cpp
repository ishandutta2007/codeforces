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

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int n, t;
int p[maxn], q[maxn], ans[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    //scanf("%d", &n);
    while (cin >> n) {
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        scanf("%d", &t);
        for (int i = 0; i < t; i++) scanf("%d", &q[i]);
        reverse(p, p + n);
        for (int i = 0; i < t; i++) q[i] = n - q[i];
        sort(q, q + t);
        
        int cnt = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (v.empty() || v.back() != p[i] || q[cnt] == i) {
                v.push_back(p[i]);
                ans[i] = p[i];
                cnt += q[cnt] == i;
                continue;
            }
            v.pop_back();
            ans[i] = -p[i];
        }
        if (v.empty()) {
            cout << "YES" << endl;
            for (int i = n - 1; i >= 0; i--) cout << -ans[i] << " \n"[!i];
        } else {
            cout << "NO" << endl;
        }
    }
    
	return 0;
}