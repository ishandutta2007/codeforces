#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXT = 530000;
	struct node{
		int subMax, subMin;
		bool decpair, incpair;
	};
	node operator+(node a, node b){
		node ret;
		ret.subMax = max(a.subMax, b.subMax);
		ret.subMin = min(a.subMin, b.subMin);
		ret.decpair = (a.decpair | b.decpair | (a.subMax > b.subMin));
		ret.incpair = (a.incpair | b.incpair | (a.subMin < b.subMax));
		return ret;
	}

struct seg{
	int lim;
	node tree[MAXT];
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i = 0; i < MAXT; i++){
			tree[i] = {int(-1e9), int(1e9), 0, 0};
		}
	}
	void remove(int x){
		x += lim;
		tree[x] = {int(-1e9), int(1e9), 0, 0};
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	void add(int x, int v){
		x += lim;
		tree[x] = {v, v, 0, 0};
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	node query(int s, int e){
		s += lim;
		e += lim;
		node L = {int(-1e9), int(1e9), 0, 0};
		node R = {int(-1e9), int(1e9), 0, 0};
		while(s < e){
			if(s%2 == 1) L = L + tree[s++];
			if(e%2 == 0) R = tree[e--] + R;
			s >>= 1;
			e >>= 1;
		}
		if(s == e) L = L + tree[s];
		return (L + R);
	}
}seg;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> mxEnd(n);
	auto Report = [&](int s, int e){
		mxEnd[s] = max(mxEnd[s], e);
	};
	vector<int> a(n);
	vector<pi> intv(n); // half open
	vector<int> upLeft(n), upRight(n), dnLeft(n), dnRight(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	{
		vector<int> stk;
		for(int i = 0; i < n; i++){
			while(sz(stk) && a[stk.back()] > a[i]) stk.pop_back();
			dnLeft[i] = (sz(stk) ? stk.back() : -1);
			stk.push_back(i);
		}
		stk.clear();
		for(int i = 0; i < n; i++){
			while(sz(stk) && a[stk.back()] < a[i]) stk.pop_back();
			upLeft[i] = (sz(stk) ? stk.back() : -1);
			stk.push_back(i);
		}
		stk.clear();
		for(int i = n - 1; i >= 0; i--){
			while(sz(stk) && a[stk.back()] < a[i]) stk.pop_back();
			upRight[i] = (sz(stk) ? stk.back() : n);
			stk.push_back(i);
		}
		stk.clear();
		for(int i = n - 1; i >= 0; i--){
			while(sz(stk) && a[stk.back()] > a[i]) stk.pop_back();
			dnRight[i] = (sz(stk) ? stk.back() : n);
			stk.push_back(i);
		}
		stk.clear();
	}
	int j = 0;
	seg.init(n);
	for(int i = 0; i < n; i++){
		seg.add(a[i], i);
		while(seg.query(1, a[i]).decpair || seg.query(a[i], n).incpair){
			seg.remove(a[j++]);
		}
		intv[i].first = j;
		Report(j, i + 1);
	}
	seg.init(n);
	j = n;
	for(int i = n - 1; i >= 0; i--){
		seg.add(a[i], i);
		while(seg.query(1, a[i]).incpair || seg.query(a[i], n).decpair){
			seg.remove(a[--j]);
		}
		intv[i].second = j;
		Report(i, j);
	}
	for(int i = 1; i < n; i++){
		int center = a[i];
		int upThres = (upRight[i] < intv[i].second ? a[upRight[i]] : 1e9);
		int dnThres = (dnRight[i] < intv[i].second ? a[dnRight[i]] : -1e9);
		int rcenter = a[i - 1];
		int rUpThres = (upLeft[i - 1] >= intv[i - 1].first ? a[upLeft[i - 1]] : 1e9);
		int rDnThres = (dnLeft[i - 1] >= intv[i - 1].first ? a[dnLeft[i - 1]] : -1e9);
		if(rcenter < center){
			if(rUpThres < dnThres){
				Report(upLeft[i - 1] + 1, intv[i].second);
				Report(intv[i - 1].first, dnRight[i]);
			}
			else Report(intv[i - 1].first, intv[i].second);
		}
		else{
			if(rDnThres > upThres){
				Report(dnLeft[i - 1] + 1, intv[i].second);
				Report(intv[i - 1].first, upRight[i]);
			}
			else Report(intv[i - 1].first, intv[i].second);
		}
	}
	lint ans = 0;
	for(int i = 1; i < n; i++) mxEnd[i] = max(mxEnd[i], mxEnd[i - 1]);
	for(int i = 0; i < n; i++){
		ans += mxEnd[i] - i;
	}
	cout << ans << endl;
}