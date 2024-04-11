#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct seg{
	int s, e, x;
	bool operator<(const seg &s)const{
		return x < s.x;
	}
};

struct sweep{
	int idx, pos, val;
	bool operator<(const sweep &s)const{
		return pi(idx, val) < pi(s.idx, s.val);
	}
};

struct disj{
	int pa[200050];
	void init(int n){
		for(int i=1; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int xsz, ysz;
vector<seg> xs, ys; 

int ds[400050];

const int B = 400;
int bkt[1005][405];
int rep[1005];

void bkt_push(int x){
	if(rep[x] == 0) return;
	for(int i=0; i<B; i++){
		if(bkt[x][i]){
			bkt[x][i] = rep[x];
		}
	}
	rep[x] = 0;
}

void bkt_insert(int p, int v){
	bkt_push(p / B);
	bkt[p / B][p % B] = v;
}

void bkt_merge(int s, int e, int x){
	if(s/B == e/B){
		bkt_push(s/B);
		for(int i=s%B; i<=e%B; i++){
			if(bkt[s/B][i]){
				disj.uni(bkt[s/B][i], x);
			}
		}
		return;
	}
	if(s%B) bkt_push(s/B);
	while(s % B){
		if(bkt[s/B][s%B]){
			disj.uni(bkt[s/B][s%B], x);
		}
		s++;
	}
	if(e%B != B-1) bkt_push(e/B);	
	while(e%B != B-1){
		if(bkt[e/B][e%B]){
			disj.uni(bkt[e/B][e%B], x);
		}
		e--;
	}
	for(int i=s/B; i<=e/B; i++){
		if(rep[i]){
			disj.uni(rep[i], x);
		}
		else{
			int chk = 0;
			for(int j=0; j<B; j++){
				if(bkt[i][j]){
					disj.uni(bkt[i][j], x);
					chk++;
				}
			}
			if(chk) rep[i] = x;
		}
	}
}

struct bit{
	int tree[400050];
	void add(int x, int v){
		while(x <= xsz){
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

lint get_intersection(){
	vector<sweep> swp;
	for(auto &i : xs){
		swp.push_back({i.s, i.x, 1});
		swp.push_back({i.e+1, i.x, -1});
	}
	sort(swp.begin(), swp.end());
	lint ret = 0;
	int p = 0;
	for(auto &j : ys){
		while(p < swp.size() && swp[p].idx <= j.x){
			bit.add(swp[p].pos, swp[p].val);
			p++;
		}
		ret += bit.query(j.e) - bit.query(j.s-1);
	}
	return ret;
}

int main(){
	vector<int> vx, vy;
	int w = 1e6;
	int h = 1e6;
	vx.push_back(0);
	vx.push_back(w);
	vy.push_back(0);
	vy.push_back(h);
	int n1, n2, n;
	scanf("%d %d",&n1,&n2);
	n = n1 + n2;
	for(int i=0; i<n1; i++){
		int y1, x1, x2;
		scanf("%d %d %d",&y1,&x1,&x2);
		ys.push_back({x1, x2, y1});
	}
	for(int i=0; i<n2; i++){
		int y1, x1, x2;
		scanf("%d %d %d",&y1,&x1,&x2);
		xs.push_back({x1, x2, y1});
	}

	xs.push_back({0, h, 0});
	xs.push_back({0, h, w});
	ys.push_back({0, w, 0});
	ys.push_back({0, w, h});
	for(auto &i : ys){
		vx.push_back(i.s);
		vx.push_back(i.e);
		vy.push_back(i.x);
	}
	for(auto &i : xs){
		vy.push_back(i.s);
		vy.push_back(i.e);
		vx.push_back(i.x);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	for(auto &i : xs){
		int l = lower_bound(vy.begin(), vy.end(), i.s) - vy.begin();
		int r = upper_bound(vy.begin(), vy.end(), i.e) - vy.begin() - 1;
		int x = lower_bound(vx.begin(), vx.end(), i.x) - vx.begin();
		i = {l+1, r+1, x+1};
	}
	for(auto &i : ys){
		int l = lower_bound(vx.begin(), vx.end(), i.s) - vx.begin();
		int r = upper_bound(vx.begin(), vx.end(), i.e) - vx.begin() - 1;
		int x = lower_bound(vy.begin(), vy.end(), i.x) - vy.begin();
		i = {l+1, r+1, x+1};
	}
	xsz = vx.size();
	ysz = vy.size();
	cout << get_intersection() - (n + 3) << endl;
}