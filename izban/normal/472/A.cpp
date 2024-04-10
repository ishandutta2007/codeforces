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

bool isPr(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;;
    }
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int n;
    while (cin >> n) {
        for (int i = 3; i < n; i++) {
            if (!isPr(i) && !isPr(n - i)) {
                cout << i << " " << n - i << endl;
                break;
            }
        }
    }
    
    return 0;
}