#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int c[N], d[N], e[N];
vector<int> v[N];

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		fill(c+1, c+n+1, 0);
		fill(d+1, d+n+1, 0);
		fill(e+1, e+n+1, 0);
		for(int i = 0, x, y; i < n; i++){
			scanf("%d%d", &x, &y);
			c[x]++;
			d[x] += y;
		}
		priority_queue<int> pq;
		for(int i = 0; i <= n; i++) pq.push(c[i]);
		int a = 0, b = 0;
		for(int i = n; i >= 1; i--){
			if(pq.top() < i) continue;
			pq.pop();
			e[i] = 1;
			a += i;
		}
		while(!pq.empty()) pq.pop();
		for(int i = 1; i <= n; i++) v[c[i]].push_back(d[i]);
		for(int i = n; i >= 1; i--){
			for(int j : v[i]) pq.push(j);
			if(e[i]){
				b += min(i, pq.top());
				pq.pop();
			}
		}
		for(int i = 0; i <= n; i++) v[i].clear();
		printf("%d %d\n", a, b);
	}
}