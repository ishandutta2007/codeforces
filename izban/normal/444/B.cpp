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

int n, d;
int a[maxn], b[maxn], c[maxn], o[maxn];
ll x;

//x -  64- 
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while (cin >> n >> d >> x) {
        initAB();
        //for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
        //for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
        vector<int> pos;
        for (int i = 0; i < n; i++) if (b[i]) pos.push_back(i);
        for (int i = 0; i < n; i++) c[i] = 0;
        for (int i = 0; i < n; i++) o[a[i]] = i;
        
        int cnt = n, cur = n;
        while (cnt > 500 && cur >= 0) {
            for (int i = 0; i < (int)pos.size(); i++) {
                if (o[cur] + pos[i] < n && c[o[cur] + pos[i]] == 0) {
                    c[o[cur] + pos[i]] = cur;
                    cnt--;
                }
            }
            cur--;
        }
        for (int i = 0; i < n; i++) if (c[i] == 0) {
            for (int j = 0; j < (int)pos.size() && i - pos[j] >= 0; j++) {
                c[i] = max(c[i], a[i - pos[j]]);
            }
        }
        //cerr << n << " " << d << " " << x << endl;
        for (int i = 0; i < n; i++) printf("%d\n", c[i]);
    }
    
    return 0;
}