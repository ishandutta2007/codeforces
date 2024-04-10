#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx,tune=native")

#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

#define BK 100

const int MAXBIT = 16;

using namespace std;

int n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int f[DMAX];

struct node {
	int stop = 0;
	node *p[2];

	node(int stop = 0) {
		p[0] = p[1] = 0;
	}
};	

struct Trie {
	
private:

	int limit;
	
	void ins(node * k, int nr, int bit) {
		if(bit < 0) {
			k->stop = 1;
			return;
		}

		bool b = (nr & (1 << bit)) != 0;
		if(k->p[b] == 0) k->p[b] = new node();
		ins(k->p[b], nr, bit - 1);
	}

	int que(node * k, int x, int bit, int offset) {
		// dbg(offset);
		// dbg(bit);
		if(bit < 0) {
			if(k->stop) 
				return offset;
			return -1;
		}

		if(offset + (1 << bit) > limit) {
			// dbg_ok;
			if(k->p[0])
				return que(k->p[0], x, bit - 1, offset);
			return -1;
		}
		
		// dbg(bit);
		// dbg(x);
		bool b = ((x & (1 << bit)) == 0);
		// dbg(b); 
		int r = -1;
		
		if(k->p[b])
			r = que(k->p[b], x, bit - 1, offset + b * (1 << bit));
		
		if(r == -1 && k->p[1 - b])
			r = que(k->p[1 - b], x, bit - 1, offset + (1 - b) * (1 << bit));;
		
		return r; 
	}

public:
	node * root = new node();

	void insert(int nr) {
		ins(root, nr, MAXBIT);
	}

	int query(int lim, int x) {
		limit = lim;
		return que(root, x, MAXBIT, 0);
	}

}T[DMAX];

int main() {

	ios_base::sync_with_stdio(false);

	int q, t, x;
	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> t;
		if(t == 1) {
			cin >> x;
			if(f[x]) 
				continue;
			
			f[x] = 1;
			for(int j = 1; j * j <= x; j++) {
				if(x % j) continue;
				T[j].insert(x);
				T[x / j].insert(x);
			}
		}
		else {
			int s;
			cin >> x >> k >> s;
			if(s - x <= 0 || x % k != 0) {
				cout << "-1\n";
				continue;
			}
			cout << T[k].query(s - x, x) << '\n';
			// int limit = s - x;
			// if(false) {
			// 	int ans = -1;
			// 	for(int j = 0; j <= limit / k + 1; j++) {
			// 		int nr = j * k;
			// 		if(f[nr] == 0 || nr + x > s) continue;
			// 		if((nr ^ x) > (ans ^ x)) 
			// 			ans = nr;
			// 	}
			// 	cout << ans << '\n';
			// }
		}
	}

	// update_tree(1, 1, 0, N-1, 0, N - 1, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	// update_tree_pos(1, 1, 0, N-1, 21, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	// update_tree(1, 1, 0, N-1, 0, N - 1, 7); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	// // update_tree[tr](1, 0, N-1, 0, 7, 7); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	// // update_tree[tr](1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

	// cout << query_tree(1, 1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}