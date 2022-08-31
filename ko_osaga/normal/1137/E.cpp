#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef double llf;
typedef pair<lint, lint> pi;
const int MAXN = 300005;

int ccw(pi a, pi b, pi c){
	lint dx1 = b.first - a.first;
	lint dy1 = b.second - a.second;
	lint dx2 = c.first - a.first;
	lint dy2 = c.second - a.second;
	llf fuck = 1.0 * dx1 * dy2 - 1.0 * dy1 * dx2;
	if(fuck > 1e18) return 1;
	if(fuck < -1e18) return -1;
	lint real = dx1 * dy2 - dy1 * dx2;
	if(real > 0) return 1;
	if(real < 0) return -1;
	return 0;
}

struct bentleySaxe{
	vector<lint> sz;
	vector<lint> a;
	vector<pi> cvxh;
	lint lazyB, lazyC, totCar;
	void clear(){
		sz.clear(); a.clear(); cvxh.clear();
		lazyB = lazyC = totCar = 0;
	}
	void init(vector<lint> _sz, vector<lint> _a){
		lazyB = lazyC = 0;
		a = _a;
		sz = _sz;
		totCar = accumulate(sz.begin(), sz.end(), 0ll);
		cvxh.clear();
		lint cursum = 0;
		for(int i=0; i<a.size(); i++){
			while(cvxh.size() >= 2 && ccw(cvxh[cvxh.size() - 2], cvxh.back(), pi(cursum, a[i])) <= 0) cvxh.pop_back();
			cvxh.emplace_back(cursum, a[i]);
			cursum += sz[i];
		}
	}
	void add_val(lint b, lint c){
		lazyB += b;
		lazyC += c;
	}
	pi query(lint cursum){
		pi ret(1e18, 1e18);
		if(a.empty()) return ret;
		int s = 0, e = cvxh.size() - 1;
		while(s != e){
			int m = (s+e)/2;
			if(cvxh[m].second + cvxh[m].first * lazyC <= cvxh[m+1].second + cvxh[m+1].first * lazyC) e = m;
			else s = m + 1;
		}
		ret.first = cvxh[s].second + (0 + cvxh[s].first) * lazyC;
		ret.second = cvxh[s].first + cursum;
		ret.first += lazyB;
		ret.second++;
		return ret;
	}
	int size(){ return a.size(); }
	lint total_car(){ return totCar; }
	void do_lazy(){
		lint cursum = 0;
		for(int i=0; i<a.size(); i++){
			a[i] = lazyB + a[i] + lazyC * cursum;
			cursum += sz[i];
		}
		lazyB = lazyC = 0;
	}

}L[20], R[20];

bentleySaxe merge(bentleySaxe X, bentleySaxe Y){
	X.do_lazy();
	Y.do_lazy();
	vector<lint> szv, av;
	for(int i=0; i<X.size(); i++){
		szv.push_back(X.sz[i]);
		av.push_back(X.a[i]);
	}
	for(int i=0; i<Y.size(); i++){
		szv.push_back(Y.sz[i]);
		av.push_back(Y.a[i]);
	}
	bentleySaxe ret;
	ret.init(szv, av);
	return ret;
}

int main(){
	int n, q;
	scanf("%d %d",&n,&q);
	R[0].init({n}, {0});
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int n; scanf("%d",&n);
			bentleySaxe bs;
			bs.init({n}, {0});
			for(int j=0; j<20; j++){
				bs = merge(bs, L[j]);
				L[j].clear();
				if(bs.size() <= (1<<j)){
					L[j] = bs;
					break;
				}
			}
		}
		if(t == 2){
			int n; scanf("%d",&n);
			bentleySaxe bs;
			bs.init({n}, {0});
			for(int j=0; j<20; j++){
				bs = merge(R[j], bs);
				R[j].clear();
				if(bs.size() <= (1<<j)){
					R[j] = bs;
					break;
				}
			}
		}
		if(t == 3){
			lint b, c; scanf("%lld %lld",&b,&c);
			for(int j=0; j<20; j++){
				L[j].add_val(b, c);
				b += c * L[j].total_car();
			}
			for(int j=19; j>=0; j--){
				R[j].add_val(b, c);
				b += c * R[j].total_car();
			}
		}
		lint cursum = 0;
		pi ret(1e18, 1e18);
		for(int j=0; j<20; j++){
			ret = min(ret, L[j].query(cursum));
			cursum += L[j].total_car();
		}
		for(int j=19; j>=0; j--){
			ret = min(ret, R[j].query(cursum));
			cursum += R[j].total_car();
		}
		printf("%lld %lld\n", ret.second, ret.first);
	}
}