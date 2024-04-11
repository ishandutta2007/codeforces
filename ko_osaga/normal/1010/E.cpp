#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 100050;

int n, m, q;
int a, b, c, lx, ly, lz, rx, ry, rz;
int x[MAXN], y[MAXN], z[MAXN];

struct query{ int x, y, z, idx;
	bool operator<(const query &q)const{
		return x > q.x;
	}
};
vector<query> qry;
int fucked[MAXN];

struct seg{
	int tree[MAXN];
	void upd(int x, int v){
		while(x < MAXN){
			tree[x] = max(tree[x], v);
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret = max(ret, tree[x]);
			x -= x & -x;
		}
		return ret;
	}
	void clear(){
		memset(tree, 0, sizeof(tree));
	}
}seg;

void Fuck(){
	vector<query> ans;
	vector<query> ban;
	for(auto &i : qry){
		if(i.x <= rx && i.y <= ry && i.z <= rz){
			ans.push_back({min(lx, i.x), min(ly, i.y), min(lz, i.z), i.idx});
		}
	}
	for(int i=0; i<m; i++){
		if(x[i] <= rx && y[i] <= ry && z[i] <= rz){
			ban.push_back({x[i], y[i], z[i], -1});
		}
	}
	sort(ans.begin(), ans.end());
	sort(ban.begin(), ban.end());
	seg.clear();
	int ptr = 0;
	for(int i=0; i<ans.size(); i++){
		while(ptr < ban.size() && ban[ptr].x >= ans[i].x){
			seg.upd(ry + 1 - ban[ptr].y, ban[ptr].z);
			ptr++;
		}
		if(seg.query(ry + 1 - ans[i].y) >= ans[i].z){
			fucked[ans[i].idx] = true;
		}
	}
}

int main(){
	scanf("%d %d %d %d %d %d",&a,&b,&c,&n,&m,&q);
	lx = ly = lz = 1e9;
	rx = ry = rz = -1e9;
	for(int i=0; i<n; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		lx = min(lx, x);
		ly = min(ly, y);
		lz = min(lz, z);
		rx = max(rx, x);
		ry = max(ry, y);
		rz = max(rz, z);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
	}
	for(int i=0; i<q; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		qry.push_back((query){x, y, z, i});
	}
	auto in = [&](int s, int m, int e){
		return s <= m && m <= e;
	};
	for(int i=0; i<m; i++){
		if(in(lx, x[i], rx) && in(ly, y[i], ry) && in(lz, z[i], rz)){
			puts("INCORRECT");
			return 0;
		}
	}
	for(int i=0; i<8; i++){
		if(i & 4) tie(lx, rx) = pi(a + 1 - rx, a + 1 - lx);
		if(i & 2) tie(ly, ry) = pi(b + 1 - ry, b + 1 - ly);
		if(i & 1) tie(lz, rz) = pi(c + 1 - rz, c + 1 - lz);
		if(i & 4){
			for(auto &i : qry) i.x = a + 1 - i.x;
			for(int i=0; i<m; i++) x[i] = a + 1 - x[i];
		}
		if(i & 2){
			for(auto &i : qry) i.y = b + 1 - i.y;
			for(int i=0; i<m; i++) y[i] = b + 1 - y[i];
		}
		if(i & 1){
			for(auto &i : qry) i.z = c + 1 - i.z;
			for(int i=0; i<m; i++) z[i] = c + 1 - z[i];
		}
		Fuck();
		if(i & 4){
			for(auto &i : qry) i.x = a + 1 - i.x;
			for(int i=0; i<m; i++) x[i] = a + 1 - x[i];
		}
		if(i & 2){
			for(auto &i : qry) i.y = b + 1 - i.y;
			for(int i=0; i<m; i++) y[i] = b + 1 - y[i];
		}
		if(i & 1){
			for(auto &i : qry) i.z = c + 1 - i.z;
			for(int i=0; i<m; i++) z[i] = c + 1 - z[i];
		}
		if(i & 4) tie(lx, rx) = pi(a + 1 - rx, a + 1 - lx);
		if(i & 2) tie(ly, ry) = pi(b + 1 - ry, b + 1 - ly);
		if(i & 1) tie(lz, rz) = pi(c + 1 - rz, c + 1 - lz);
	}
	puts("CORRECT");
	for(int i=0; i<q; i++){
		if(fucked[i]){
			puts("CLOSED");
		}
		else if(in(lx, qry[i].x, rx) && in(ly, qry[i].y, ry) && in(lz, qry[i].z, rz)){
			puts("OPEN");
		}
		else puts("UNKNOWN");
	}
}