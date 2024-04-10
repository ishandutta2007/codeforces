#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>

using namespace std;

#pragma comment(linker, "/STACK:100000000")

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define ll long long
#define ull unsigned long long
#define sz(x) (int)(x).size()

vector<pair<int, int> > v[555]; // ,  
bool vis[555];

inline void go(int s, int l, int r) {
    vis[s] = true;
    for(int i = 0, maxi = sz(v[s]); i < maxi && v[s][i].second < l; i++) {
        if(!vis[v[s][i].first]) go(v[s][i].first, l, r);
    }
    for(int i = sz(v[s]) - 1; i >= 0 && v[s][i].second > r; i--) {
        if(!vis[v[s][i].first]) go(v[s][i].first, l, r);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].pb(mp(y, i));
        v[y].pb(mp(x, i));
    }
    int k;
    scanf("%d", &k);
    for(int test = 0; test < k; test++) {
        int l, r;
        scanf("%d %d", &l, &r);
        for(int i = 0; i < 555; i++) vis[i] = false;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) go(i, l, r), res++;
        }
        printf("%d\n", res);
    }
    return 0;
}