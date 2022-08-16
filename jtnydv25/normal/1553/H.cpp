#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif
int store[20][1 << 20];

struct trie{
	int k;
	struct Node{
		Node* ch[2];
		Node(){
			ch[0] = ch[1] = NULL;
		}
	};
	Node* root;
	trie(int k) : k(k){root = new Node();}
	void insert(int x){
		Node* cur = root;
		for(int i = k - 1; i >= 0; i--){
			int side = x >> i & 1;
			if(!cur->ch[side]) cur->ch[side] = new Node();
			cur = cur->ch[side];
		}
	}
	void eval(){
		vector<int> ret(1 << k);
		for(int i = 0; i <= k; i++) fill(store[i], store[i] + (1 << k), 1 << 30);
		function<vector<pii>(Node*, int)> dfs = [&](Node* node, int h){
			if(!node) return vector<pii>();
			if(h == 0){
				vector<pii> ret = {{0, 0}};
				return ret;
			}
			vector<pii> A = dfs(node->ch[0], h - 1), B = dfs(node->ch[1], h - 1);

			vector<pii> ret(1 << h);
			for(int x = 0; x < (1 << h); x++){
				int add = 1 << (h - 1);
				int rem = x & (add - 1);
				if(x >> (h - 1) & 1){
					ret[x].first = node->ch[1] ? B[rem].first : A[rem].first + add;
					ret[x].second = node->ch[0] ? A[rem].second + add : B[rem].second;
				} else{
					ret[x].first = node->ch[0] ? A[rem].first : B[rem].first + add;
					ret[x].second = node->ch[1] ? B[rem].second + add : A[rem].second;
				}

				if(!A.empty() && !B.empty()){
					if(x >> (h - 1) & 1) store[h][x] = min(store[h][x], A[rem].first + add - B[rem].second);
					else store[h][x] = min(store[h][x], B[rem].first + add - A[rem].second);
				}
				assert(max(ret[x].first, ret[x].second) < (1 << h) && min(ret[x].first, ret[x].second) >= 0);
			}
			return ret;
		};
		dfs(root, k);

	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, k; cin >> n >> k;
	trie T(k);
	for(int i = 0; i < n;i++){
		int x; cin >> x;
		T.insert(x);
	}
	T.eval();
	for(int x = 0; x < (1 << k); x++){
		int ans = 1 << 30;
		for(int h = k; h; h--){
			ans = min(ans, store[h][x & ((1 << h) - 1)]);
		}
		cout << ans << " ";
	}
	cout << endl;
}