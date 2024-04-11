#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 300005;

int n;
int a[MAXN];
int rev[MAXN];
vector<pi> seq;

int mode(int x){
	if(x == 1) return 1;
	if(x == n) return 2;
	if(x <= n / 2) return 2;
	return 1;
}

void Swap(int x, int y){
	if(x == y) return;
	swap(a[x], a[y]);
	swap(rev[a[x]], rev[a[y]]);
	seq.emplace_back(x, y);
}

vector<int> belong[3];

vector<int> route(int x, int y){
	vector<int> v = {x};
	if(x <= n / 2) v.push_back(n);
	else v.push_back(1);
	if(v.back() == y) return v;
	if(abs(v.back() - y) < n / 2){
		v.push_back(n + 1 - v.back());
	}
	if(v.back() == y) return v;
	v.push_back(y);
	return v;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) rev[a[i]] = i;
	for(int i=1; i<=n; i++){
		if(rev[i] == i) continue;
		vector<int> r = route(i, rev[i]);
		for(int i=1; i<r.size(); i++) Swap(r[i-1], r[i]);
		for(int i=(int)r.size()-3; i>=0; i--) Swap(r[i], r[i+1]);
	}
	assert(is_sorted(a + 1, a + n + 1));
	cout << seq.size() << endl;
	for(auto &i : seq){
		printf("%d %d\n",i.first, i.second);
	}
}