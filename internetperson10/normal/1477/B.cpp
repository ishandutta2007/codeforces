#include <bits/stdc++.h>

using namespace std;

struct segTree {
	int size = 1;
	vector<int> nums, ops;
	void init(int n, vector<int> v) {
		vector<int>().swap(ops);
		vector<int>().swap(nums);
		size = 1;
		while(size < n) size *= 2;
		v.resize(size, 0);
		nums.resize(2*size, 0);
		ops.resize(2*size, -1);
		for(int i = size-1; i < 2*size-1; i++) {
			nums[i] = v[i - size + 1];
		}
		for(int i = size-2; i >= 0; i--) {
			nums[i] = nums[2*i+1] + nums[2*i+2];
		}
		// print();
	}
	void prop(int n, int lx, int rx) {
		if(ops[n] == -1) return;
		if(rx - lx == 1) return;
		int mid = (lx + rx)/2;
		nums[2*n+1] = ops[n] * (mid - lx);
		nums[2*n+2] = ops[n] * (rx - mid);
		ops[2*n+1] = ops[2*n+2] = ops[n];
		ops[n] = -1;
		return;
	}
	void set(int l, int r, int v, int n, int lx, int rx) {
		if(rx <= l || r <= lx) return;
		if(l <= lx && rx <= r) {
			nums[n] = (rx - lx)*v;
			ops[n] = v;
			return;
		}
		// prop(n, lx, rx);
		int mid = (lx + rx)/2;
		set(l, r, v, 2*n+1, lx, mid);
		set(l, r, v, 2*n+2, mid, rx);
		nums[n] = nums[2*n+1] + nums[2*n+2];
	}
	void set(int l, int r, int v) {
		set(l, r, v, 0, 0, size);
	}
	int get(int l, int r, int n, int lx, int rx) {
		prop(n, lx, rx);
		if(rx <= l || r <= lx) return 0;
		if(l <= lx && rx <= r) return nums[n];
		int mid = (lx + rx)/2;
		return get(l, r, 2*n+1, lx, mid) + get(l, r, 2*n+2, mid, rx);
	}
	int get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	void propAll() {
		vector<int> eks;
		eks.resize(2*size);
		for(int i = size-1; i < 2*size-1; i++) {
			eks[i] = 1;
		}
		for(int i = size-2; i >= 0; i--) {
			eks[i] = eks[2*i+1] + eks[2*i+2];
		}
		for(int i = 0; i < 2*size-1; i++) {
			prop(i, 0, eks[i]);
		}
	}
	bool check(int n, vector<int> v) {
		propAll();
		// prop(0, 0, size);
		// print();
		for(int i = 0; i < n; i++) {
			if(nums[size - 1 + i] != v[i]) return true;
		}
		return false;
	}
	void print() {
		// propAll();
		prop(0, 0, size);
		for(int i = 0; i < 2*size; i++) cout << nums[i] << "  ";
		cout << '\n';
		for(int i = 0; i < 2*size; i++) cout << ops[i] << ' ';
		cout << '\n';
	}
};

vector<int> qs, v;

int main() {
	int t;
	cin >> t;
	segTree st;
	while(t--) {
		int n, q;
		cin >> n >> q;
		string s1, s2;
		cin >> s1 >> s2;
		vector<int>().swap(v);
		v.resize(n);
		for(int i = 0; i < n; i++) {
			if(s2.at(i) == '0') v[i] = 0;
			else v[i] = 1;
		}
		st.init(n, v);
		qs.resize(2*q);
		bool sad = false;
		for(int i = 0; i < 2*q; i++) cin >> qs[i];
		for(int i = 2*q - 2; i >= 0; i -= 2) {
			int l = qs[i]-1, r = qs[i+1];
			int x = st.get(l, r), g = 0;
			if(2*x < r - l) g = 0;
			else if(2*x > r - l) g = 1;
			else sad = true;
			// cout << l << ' ' << r << ' ' << g << ' ' << sad << '\n';
			st.set(l, r, g);
			// st.print();
		}
		vector<int>().swap(v);
		v.resize(n);
		for(int i = 0; i < n; i++) {
			if(s1.at(i) == '0') v[i] = 0;
			else v[i] = 1;
		}
		sad |= st.check(n, v);
		if(sad) cout << "NO\n";
		else cout << "YES\n";
		vector<int>().swap(qs);
	}
}