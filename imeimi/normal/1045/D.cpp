#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int B = 400;
int n;
int pro[100000];
vector<int> edge[100000];

vector<int> vs;
int sum[B];
vector<bool> con[B];
int idx[100000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lf", &x);
        pro[i] = llround(100 * (1 - x));
	}
	for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
	}
	
	int v = 0;
	for (int i = 0; i < n; ++i) v += pro[i];
	int e = 0;
	for (int i = 0; i < n; ++i) {
        for (int j : edge[i]) {
            if (i < j) continue;
            e += pro[i] * pro[j];
        }
	}
	
	for (int i = 0; i < n; ++i) {
        if (edge[i].size() > B) {
            idx[i] = vs.size();
            vs.push_back(i);
            con[idx[i]].resize(n, false);
            for (int j : edge[i]) {
                con[idx[i]][j] = 1;
                sum[idx[i]] += pro[j];
            }
        }
        else idx[i] = -1;
	}
	
    int q;
	scanf("%d", &q);
	for (int it = 0; it < q; ++it) {
        int x;
        double p;
        scanf("%d%lf", &x, &p);
        v -= pro[x];
        int pr = pro[x];
        pro[x] = llround(100 * (1 - p));
        v += pro[x];
        if (idx[x] != -1) {
            e += sum[idx[x]] * (pro[x] - pr);
        }
        else {
            for (int j : edge[x]) {
                e += pro[j] * (pro[x] - pr);
            }
        }
        for (int i = 0; i < vs.size(); ++i) {
            if (con[i][x]) {
                sum[i] += pro[x] - pr;
            }
        }
        
        printf("%.5f\n", v / 100.0 -  e / 10000.0);
	}
	return 0;
}