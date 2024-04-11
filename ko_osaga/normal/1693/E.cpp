#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXT = 530000;

struct node{
	int a[2][2];
	node(){
		a[0][0] = a[1][1] = 0;
		a[0][1] = a[1][0] = 1e9;
	}
	node(int x){
		if(x == 0){
			a[0][0] = a[1][1] = 0;
			a[0][1] = a[1][0] = 1e9;
		}
		else if(x == 1){
			a[0][0] = a[1][0] = 1;
			a[0][1] = 1e9;
			a[1][1] = 0; 
		}
		else if(x == 2){
			a[0][1] = a[1][1] = 1;
			a[1][0] = 1e9;
			a[0][0] = 0;
		}
		else if(x == 3){
			a[0][0] = a[1][0] = a[0][1] = a[1][1] = 1;
		}
		else assert(0);
	}
	node operator+(const node &nd)const{
		node ret;
		memset(ret.a, 0x3f, sizeof(ret.a));
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					ret.a[i][k] = min(ret.a[i][k], a[i][j] + nd.a[j][k]);
				}
			}
		}
		return ret;
	}
};

struct seg{
	int lim;
	node tree[MAXT];
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
		for(int i = 0; i < MAXT; i++){
			tree[i] = node();
		}
	}
	void set(int x, int v){
		x += lim;
		tree[x] = node(v);
		while(x > 1){
			x >>= 1;
			tree[x] = tree[2*x] + tree[2*x+1];
		}
	}
	node query(int s, int e){
		s += lim;
		e += lim;
		node L = node(), R = node();
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
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	seg.init(n + 1);
	vector<int> rcnt(n + 1), lcnt(n + 1);
	for(int i = 0; i < n; i++){
		rcnt[a[i]]++;
	}
	for(int i = 0; i <= n; i++){
		seg.set(i, (rcnt[i] > 0 ? 2 : 0));
	}
	lint ans = 0;
	for(int i = 0; i < n; i++){
		rcnt[a[i]]--;
		seg.set(a[i], (lcnt[a[i]] > 0) + (rcnt[a[i]] > 0) * 2);
		if(a[i] > 0){
			auto quer = seg.query(1, a[i] - 1);
			int ret = 1e9;
			for(int i = 0; i < 4; i++) ret = min(ret, quer.a[i/2][i%2]);
			ans += ret + 1;
		}
		lcnt[a[i]]++;
		seg.set(a[i], (lcnt[a[i]] > 0) + (rcnt[a[i]] > 0) * 2);
	}
	cout << ans << endl;
}