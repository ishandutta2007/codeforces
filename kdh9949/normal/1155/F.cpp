#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 15;

int n, m, p[N], q[N], low[N], lp[N], clow[N], cnt;
vector<int> e[N];
vector<pii> tv, r;
mt19937_64 rng(123);

int rn(int s, int e){
	uniform_int_distribution dst(s, e);
	return dst(rng);
}

void f(int x, int y){
	p[x] = ++cnt;
	q[cnt] = x;
	shuffle(e[x].begin(), e[x].end(), rng);
	low[x] = clow[x] = N;
	for(int i : e[x]){
		if(i == y) continue;
		if(!p[i]){
			tv.push_back(pii(x, i));
			f(i, x);
			clow[x] = min(clow[x], clow[i]);
			if(low[x] > low[i]){
				low[x] = low[i];
				lp[x] = lp[i];
			}
		}
		else if(p[i] < p[x]){
			if(low[x] > p[i]){
				low[x] = p[i];
				lp[x] = x;
			}
		}
	}
	if(y && clow[x] >= p[x]){
		tv.push_back(pii(lp[x], q[low[x]]));
		clow[x] = low[x];
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		r.push_back(pii(x, y));
	}
	auto start = chrono::high_resolution_clock::now();
	while(1){
		auto cur = chrono::high_resolution_clock::now();
		chrono::duration<double> dt = cur - start;
		if(dt > chrono::milliseconds{1900}) break;
		tv = vector<pii>();
		cnt = 0;
		fill(p + 1, p + n + 1, 0);
		f(rn(1, n), 0);
		if(tv.size() < r.size()) r.swap(tv);
	}
	printf("%d\n", r.size());
	for(pii i : r) printf("%d %d\n", i.x, i.y);
}