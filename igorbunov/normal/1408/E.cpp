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

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

vector<int> parent(200000);
vector<int> rank1(200000);

void make_set (int v) {
    parent[v] = v;
    rank1[v] = 0;
}

int find_set (int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank1[a] < rank1[b]) {
            swap (a, b);
        }
        parent[b] = a;
        if (rank1[a] == rank1[b]) {
            rank1[a]++;
        }
    }
}


signed main() {
    int n, m;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }

    vector <pair<int, pair<int,int>>> g;
    int sum = 0;

    for (int i = 0; i < m; i++) {
    	int s;
    	cin >> s;
    	for (int j = 0; j < s; j++) {
    		int ind;
    		cin >> ind;
    		ind--;
    		sum += a[i] + b[ind];
    		g.push_back(make_pair( -a[i] - b[ind], make_pair(ind, i + n)));
    		//g.push_back(make_pair( -a[i] - b[ind], make_pair(i + n, ind)));
    	}
    }
    int cost = 0;
    vector <pair<int,int>> res;
    
    sort (g.begin(), g.end());
    vector<int> t (n);
    for (int i = 0; i < n + m; i++) {
        make_set(i);
    }
    for (int i = 0; i < g.size(); i++) {
        int a = g[i].second.first;
        int b = g[i].second.second;
        int l = g[i].first;
        if (find_set(a) != find_set(b)) {
            cost += l;
            //cout << a << " " << b << endl;
            res.push_back (make_pair (a, b));
            union_sets(a, b);
        }
    }
    //cout << cost << endl;

    cout << sum + cost;
}