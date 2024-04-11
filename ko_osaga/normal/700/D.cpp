#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, m;
int a[100005], occ[100005], ret[100005];
int dcc[100005], chk[100005];

struct qry{ 
	int s, e, idx;
	bool operator<(const qry &q)const{
		return pi(s >> 8, e) < pi(q.s >> 8, q.e);
	}
}b[100005];

vector<int> v;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		occ[a[i]]++;
	}
	for(int i=1; i<=100000; i++){
		if(occ[i] > 1000) v.push_back(i); 
	}
	memset(occ, 0, sizeof(occ));
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d %d",&b[i].s,&b[i].e);
		b[i].idx = i;
	}
	sort(b, b+m);
	int s = 1, e = 0;
	for(int i=0; i<m; i++){
		auto add = [&](int x){
			if(occ[a[x]]) dcc[occ[a[x]]]--;
			occ[a[x]]++;
			dcc[occ[a[x]]]++;
		};
		auto rem = [&](int x){
			dcc[occ[a[x]]]--;
			occ[a[x]]--;
			if(occ[a[x]]) dcc[occ[a[x]]]++;
		};
		while(s < b[i].s) rem(s++);
		while(s > b[i].s) add(--s);
		while(e < b[i].e) add(++e);
		while(e > b[i].e) rem(e--);
		priority_queue<int, vector<int>, greater<int> > pq;
		int fuck[1005] = {}, ans = 0;
		for(int i=1; i<=1000; i++){
			if(dcc[i]) fuck[i] = dcc[i];
		}
		for(auto &i : v){
			if(occ[i] > 1000) pq.push(occ[i]);
		}
		for(int i=1; i<=1000; i++){
			if(fuck[i] == 0) continue;
			if(fuck[i] >= 2){
				ans += (fuck[i] / 2) * i * 2;
				if(i * 2 <= 1000) fuck[2*i] += fuck[i] / 2;
				else{
					for(int j=0; j<fuck[i] / 2; j++) pq.push(2 * i);
				}
				fuck[i] %= 2;
			}
			if(fuck[i]){
				int e = i + 1;
				while(e <= 1000 && !fuck[e]) e++;
				if(e > 1000) pq.push(i);
				else{
					fuck[e]--;
					if(i + e <= 1000) fuck[i+e] += 1;
					else pq.push(i + e);
					ans += i + e;
					i = e-1;
				}
			}
		}
		while(pq.size() > 1){
			auto x = pq.top(); pq.pop();
			x += pq.top(); pq.pop();
			ans += x; pq.push(x);
		}
		ret[b[i].idx] = ans;
	}
	for(int i=0; i<m; i++) printf("%d\n", ret[i]);
}