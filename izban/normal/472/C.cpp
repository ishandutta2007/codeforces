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



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int n;
    while (cin >> n) {
        vector<string> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (a[i] > b[i]) swap(a[i], b[i]);
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        string cur = "";
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (cur < a[p[i]]) {
                cur = a[p[i]];
            } else if (cur < b[p[i]]) {
                cur = b[p[i]];
            } else ok = false;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}