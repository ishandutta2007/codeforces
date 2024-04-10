//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
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
 
int n;
int INF = 1e9 + 7;
const int MAXN = 400001;
vector<pair<int, int>> g[MAXN];
vector<int> g1[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
vector<pair<int, int>> bridges;
vector<int> colour(MAXN, 0);
vector<int> p(MAXN, -1);
bool used1[MAXN];
vector<int> comp(MAXN);
int k = 0;
int sizes[MAXN];


void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].first;
        if (to == p) {
            continue;
        }
        if (used[to]) {
            fup[v] = min (fup[v], tin[to]);
        } else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                used1[g[v][i].second] = 1;
                bridges.push_back(make_pair(v, to));
                //cout << v << " " << to << endl;
            }
        }
    }
}
 
void find_bridges() {
    timer = 0;
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs (i);
        }
    }
}

vector<int> G[400000];
 
void dfsvisit(int u) {
    colour[u] = 1;
    comp[u] = k;
    sizes[k]++;
    for (int i = 0; i < g[u].size(); i++) {
        pair<int, int> a = g[u][i];
        int v = a.first;
        if (used1[g[u][i].second]) {
            continue;
        }
        if (p[u] == v) {
            continue;
        }
        if (colour[v] == 0) {
            p[v] = u;
            dfsvisit(v);
        }
    }
    colour[u] = 2;
}

vector<bool> used2(400000, 0);
int last = -1;
int very_ans = -1;
void dfs1(int u, int p) {
	used2[u] = 1;
	if (p > very_ans) {
		very_ans = p;
		last = u;
	}
	for (int v : g1[u]) {
		if (!used2[v]) {
			dfs1(v, p + 1);
		}
	}
}
 
signed main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }
    find_bridges();
    k = 0;
    for (int i = 0; i < n; i++) {
        if (!colour[i]) {
            dfsvisit(i);
            k++;
        }
    }
    for (int i = 0; i < bridges.size(); i++) {
        int a = comp[bridges[i].first];
        int b = comp[bridges[i].second];
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    dfs1(0, 0);
    for (int i = 0; i < n; i++) {
    	used2[i] = 0;
    }
    dfs1(last, 0);
    cout << very_ans;
    return 0;
}