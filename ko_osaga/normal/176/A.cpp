#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int a[105][105], b[105][105], c[105][105];
int n, m, k;

int solve(int s, int e){
	priority_queue<int> pq;
	for(int i=0; i<m; i++){
		int profit = b[e][i] - a[s][i];
		for(int j=0; j<c[s][i]; j++){
			pq.push(profit);
		}
	}
	int ret = 0;
	for(int i=0; i<k && !pq.empty(); i++){
		if(pq.top() > 0) ret += pq.top();
		else break;
		pq.pop();
	}
	return ret;
}

int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		string dmp; cin >> dmp;
		for(int j=0; j<m; j++){
			cin >> a[i][j] >> b[i][j] >> c[i][j];
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j) continue;
			ret = max(ret, solve(i, j));
		}
	}
	cout << ret;
}