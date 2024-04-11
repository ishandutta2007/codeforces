#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
using lint = long long;
using pi = pair<int, int>;

struct qry{ int s, e, x; };

int n, m;
bitset<MAXN> ans;

void solve(int s, int e, vector<qry> &q, bitset<10001> bs){
	if(s == e){
		for(auto &i : q){
			bs |= (bs << i.x);
		}
		ans |= bs;
		return;
	}
	int m = (s+e)/2;
	vector<qry> l, r;
	for(auto &i : q){
		if(i.s <= s && e <= i.e){
			bs |= (bs << i.x);
		}
		else{
			if(max(i.s, s) <= min(m, i.e)) l.push_back(i);
			if(max(i.s, m+1) <= min(e, i.e)) r.push_back(i);
		}
	}
	solve(s, m, l, bs);
	solve(m+1, e, r, bs);
}

int main(){
	cin >> n >> m;
	vector<qry> Q(m);
	for(auto &i : Q){
		scanf("%d %d %d",&i.s,&i.e,&i.x);
	}
	bitset<10001> bs;
	bs[0] = 1;
	solve(1, n, Q, bs);
	vector<int> v;
	for(int i=1; i<=n; i++) if(ans[i]) v.push_back(i);
	cout << v.size() << endl;
	for(auto &i : v) printf("%d ", i);
}