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

int n, m, d;

struct fw{
	int a, b, t;
	bool operator<(const fw &a)const{
		return t < a.t;
	}
}a[305];

lint dp[150005], ndp[150005];
lint cum[150005];

int main(){
	cin >> n >> m >> d;
	for(int i=0; i<m; i++){
		cin >> a[i].a >> a[i].b >> a[i].t;
	}
	sort(a, a+m);
	int prev = a[0].t;
	for(int i=0; i<m; i++){
		int e = i;
		while(e < m && a[e].t == a[i].t) e++;
		for(int j=1; j<=n; j++){
			ndp[j] = 0;
			for(int k=i; k<e; k++){
				ndp[j] += a[k].b - abs(a[k].a - j);
			}
		}
		int dx = a[i].t - prev;
		deque<lint> dq, pos;
		int st = 1, ed = 0;
		for(int j=1; j<=n; j++){
			lint np = min(1ll * n, j + 1ll * dx * d);
			while(ed < np){
				ed++;
				while(!dq.empty() && dq.back() <= dp[ed]){
					dq.pop_back();
					pos.pop_back();
				}
				dq.push_back(dp[ed]);
				pos.push_back(ed);
			}
			int op = (int)max(1ll, j - 1ll * dx * d);
			while(!dq.empty() && pos.front() < op){
				dq.pop_front();
				pos.pop_front();
			}
			st = max(st, op);
			ndp[j] += dq.front();
		}
		prev = a[i].t;
		i = e-1;
		memcpy(dp, ndp, sizeof(dp));
	}
	cout << *max_element(dp+1, dp+n+1);
}