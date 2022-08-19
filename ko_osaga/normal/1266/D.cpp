#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 1000005;

int n, m;
lint bal[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		bal[s] += x;
		bal[e] -= x;
	}
	vector<int> l, r;
	for(int i=1; i<=n; i++){
		if(bal[i] < 0) l.push_back(i);
		if(bal[i] > 0) r.push_back(i);
	}
	char buf[55] = "";
	vector<string> ans;
	while(sz(l) && sz(r)){
		int x = l.back();
		int y = r.back();
		lint delta = min(-bal[x], bal[y]);
		sprintf(buf, "%d %d %lld\n", y, x, delta);
		string tmp = buf;
		ans.push_back(tmp);
		bal[x] += delta;
		bal[y] -= delta;
		if(bal[l.back()] == 0) l.pop_back();
		if(bal[r.back()] == 0) r.pop_back();
	}
	printf("%d\n", sz(ans));
	for(auto &i : ans) printf(i.c_str());
}