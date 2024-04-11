#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 100005;

struct bit{
	int tree[MAXN * 2];
	void add(int x, int v){
		while(x < MAXN * 2){
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

bool cmp(const pi &a, const pi &b){
	return 1ll * a.first * b.second < 1ll * a.second * b.first;
}

struct tup{
	int x, y, z;
	bool operator<(const tup &t)const{
		return x < t.x;
	}
};

#define ALL(x) (x).begin(),(x).end()

lint MERGE3(vector<tup> l, vector<tup> r){
	sort(ALL(l), [&](const tup &a, const tup &b){
		return a.y < b.y;
	});
	sort(ALL(r), [&](const tup &a, const tup &b){
		return a.y < b.y;
	});
	int ptr = 0;
	lint ans = 0;
	for(int i=0; i<r.size(); i++){
		while(ptr < l.size() && l[ptr].y < r[i].y){
			bit.add(l[ptr].z, 1);
			ptr++;
		}
		ans += bit.query(r[i].z - 1);
	}
	for(int i=0; i<ptr; i++) bit.add(l[i].z, -1);
	return ans;
}

lint solve1(vector<tup> &v, int s, int e){
	if(v.empty() || s == e) return 0;
	int m = (s+e)/2;
	vector<tup> l, r;
	for(int i=0; i<v.size(); i++){
		if(v[i].x <= m) l.push_back(v[i]);
		else r.push_back(v[i]);
	}
	lint ans = solve1(l, s, m) + solve1(r, m+1, e) + 1ll * l.size() * r.size() - MERGE3(l, r) - MERGE3(r, l);
	return ans;
}

int n, w;

int arg1[MAXN];
pi arg2[MAXN];
pi arg3[MAXN];
vector<pi> v2;

lint solve(vector<pi> &v, vector<tup> &bkt){
	vector<int> v1;
	for(int i=0; i<v.size(); i++){
		arg1[i] = v[i].first;
		arg2[i] = pi(v[i].first, v[i].second - w);
		arg3[i] = pi(v[i].first, v[i].second + w);
		v1.push_back(arg1[i]);
	}
	sort(ALL(v1));
	vector<tup> w;
	for(int i=0; i<v.size(); i++){
		int x, y, z;
		x = lower_bound(ALL(v1), arg1[i]) - v1.begin() + 1;
		y = lower_bound(ALL(v2), arg2[i], cmp) - v2.begin() + 1;
		z = lower_bound(ALL(v2), arg3[i], cmp) - v2.begin() + 1;
		w.push_back({x, y, z});
	}
	sort(ALL(w));
	bkt = w;
	return solve1(w, 1, v1.size());
}

int main(){
	scanf("%d %d",&n,&w);
	vector<pi> l, r;
	for(int i=0; i<n; i++){
		int x, v;
		scanf("%d %d",&x,&v);
		v *= -1;
		pi arg = pi(x, v);
		if(x < 0) arg = pi(-x, -v);
		if(x < 0) l.push_back(pi(-x, -v));
		else r.push_back(pi(x, v));
		v2.push_back(pi(arg.first, arg.second - w));
		v2.push_back(pi(arg.first, arg.second + w));
	}
	sort(ALL(v2), cmp);
	vector<tup> bl, br;
	lint ans = solve(l, bl);
	ans += solve(r, br);
	ans += 1ll * bl.size() * br.size();
	for(auto &i : br) swap(i.y, i.z);
	ans -= MERGE3(bl, br);
	ans -= MERGE3(br, bl);
	cout << ans << endl;
}