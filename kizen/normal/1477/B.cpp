#include <bits/stdc++.h>

using namespace std;

struct Seg{
	int n;
	vector<int> tree, lazy;
	Seg(int N):n(N){
		tree.resize(n * 4), lazy.resize(n * 4, -1);
	}
	void update(int x, int l, int r){
		if(lazy[x] == -1) return;
		tree[x] = (r - l + 1) * lazy[x];
		if(l < r) lazy[x * 2] = lazy[x], lazy[x * 2 + 1] = lazy[x];
		lazy[x] = -1;
	}
	void push(int x, int l, int r, int pl, int pr, int val){
		update(x, l, r);
		if(pr < l || pl > r) return;
		if(l >= pl && r <= pr){
			lazy[x] = val;
			update(x, l, r);
			return;
		}
		int mid = (l + r) / 2;
		push(x * 2, l, mid, pl, pr, val), push(x * 2 + 1, mid + 1, r, pl, pr, val);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}
	int get(int x, int l, int r, int fl, int fr){
		update(x, l, r);
		if(fr < l || fl > r) return 0;
		if(l >= fl && r <= fr) return tree[x];
		int mid = (l + r) / 2;
		return get(x * 2, l, mid, fl, fr) + get(x * 2 + 1, mid + 1, r, fl, fr);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, q; cin >> n >> q;
		string a, b;
		cin >> a >> b;
		Seg tree(n + 4);
		for(int i = 0; i < n; ++i){
			if(b[i] == '1'){
				tree.push(1, 0, n - 1, i, i, 1);
			}
		}
		vector<pair<int, int>> que(q);
		for(int i = 0; i < q; ++i){
			cin >> que[i].first >> que[i].second;
			--que[i].first, --que[i].second;
		}
		reverse(que.begin(), que.end());
		int f = 1;
		for(int i = 0; i < q; ++i){
			int l = que[i].first, r = que[i].second;
			int val = tree.get(1, 0, n - 1, l, r);
			int cnt = r - l + 1;
			if(val * 2 == cnt){
				f = 0;
				break;
			}
			if(val * 2 > cnt){
				tree.push(1, 0, n - 1, l, r, 1);
			}
			else{
				tree.push(1, 0, n - 1, l, r, 0);
			}
		}
		for(int i = 0; i < n; ++i){
			if(tree.get(1, 0, n - 1, i, i) != a[i] - '0'){
				f = 0;
				break;
			}
		}
		if(!f){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}