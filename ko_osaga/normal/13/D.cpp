#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int cnt[505][505];
pi a[505], b[505];
int n, m;

lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	for(int i=0; i<m; i++){
		cin >> b[i].first >> b[i].second;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=0; k<m; k++){
				if(ccw(a[i], b[k], a[j]) > 0 && a[i].first <= b[k].first && b[k].first < a[j].first){
					cnt[i][j]++;
				}
			}
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				int bpnt = cnt[i][k] - cnt[i][j] - cnt[j][k];
				if(bpnt == 0) ret++;
			}
		}
	}
	cout << ret;
}