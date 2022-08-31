#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 200005;

int n;
pi a[MAXN];

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x < MAXN){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		swap(a[i].first, a[i].second);
	}
	vector<int> vx, vy;
	for(int i=0; i<n; i++){
		vx.push_back(a[i].first);
		vy.push_back(a[i].second);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for(int i=0; i<n; i++){
		a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin() + 1;
		a[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin() + 1;
	}
	sort(a, a + n);
	set<int> s;
	lint ret = 0;
	for(int i=n-1; i>=0; i--){
		int prv = 0;
		if(i > 0 && a[i-1].first == a[i].first) prv = a[i-1].second;
		lint l = bit.query(a[i].second - 1) - bit.query(prv) + 1;
		lint r = bit.query(n) - bit.query(a[i].second) + 1;
		ret += l * r;
		if(s.find(a[i].second) == s.end()){
			s.insert(a[i].second);
			bit.add(a[i].second, 1);
		}
	}
	cout << ret << endl;
}