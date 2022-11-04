#include<bits/stdc++.h>
#define MX 1073741824
//#define MX 1000000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int obr1[31];

struct Node {
	Node* l = nullptr;
	Node* r = nullptr;
	int sum = 0;
	int sub = -1;
	int add = 0;
	bool fill0 = false;
};

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}
int obr2(int a) {
	return bin_pow(a, mod - 2);
}

int obr(int a) {
	if(__builtin_popcount(a) == 1) {
		return obr1[__builtin_ctz(a)];
	}
	return bin_pow(a, mod - 2);
}

void precalc() {
	int now = 1;
	for(int i = 0; i < 31; i++) {
		obr1[i] = obr2(now);
		now *= 2;
	}
}

void push1(Node* root, int l, int r) {
	int mid = (l + r) / 2;
	if(l != r && root->l == nullptr) {
		root->r = new Node();
		root->l = new Node();
		root->l->sum = ((ll)root->sum * obr(r - l + 1) % mod * (mid - l + 1)) % mod;
		root->r->sum = ((ll)root->sum * obr(r - l + 1) % mod * (r - mid)) % mod;
	}
	if(root->fill0) {
		root->fill0 = false;
		root->sum = 0;
		root->sub = -1;
		root->add = 0;
		if(l != r) {
			root->l->fill0 = true;
			root->r->fill0 = true;
		}
	}
}

void push(Node* root, int l, int r) {
	int mid = (l + r) / 2;
	if(l != r && root->l == nullptr) {
		root->r = new Node();
		root->l = new Node();
		root->l->sum = ((ll)root->sum * obr(r - l + 1) % mod * (mid - l + 1)) % mod;
		root->r->sum = ((ll)root->sum * obr(r - l + 1) % mod * (r - mid)) % mod;
	}
	push1(root, l, r);
	if(l == r) {
		if(root->sub != -1) {
			root->sum = (root->sub - root->sum + mod) % mod;
			root->sub = -1;
		} else {
			root->sum = (root->sum + root->add) % mod;
			root->add = 0;
		}
		return;
	}
	push1(root->l, l, mid);
	push1(root->r, mid + 1, r);
	if(root->sub != -1) {
		root->sum = ((ll)root->sub * (r - l + 1) - root->sum + mod) % mod;
		if(root->l->sub != -1) {
			root->l->add = (root->sub - root->l->sub + mod) % mod;
			root->l->sub = -1;
		} else {
			root->l->sub = (root->sub - root->l->add + mod) % mod;
			root->l->add = 0;
		}
		if(root->r->sub != -1) {
			root->r->add = (root->sub - root->r->sub + mod) % mod;
			root->r->sub = -1;
		} else {
			root->r->sub = (root->sub - root->r->add + mod) % mod;
			root->r->add = 0;
		}
		root->sub = -1;
	} else {
		root->sum = ((ll)root->add * (r - l + 1) + root->sum) % mod;
		if(root->l->sub != -1) {
			root->l->sub = (root->l->sub + root->add) % mod;
		} else {
			root->l->add = (root->l->add + root->add) % mod;
		}
		if(root->r->sub != -1) {
			root->r->sub = (root->r->sub + root->add) % mod;
		} else {
			root->r->add = (root->r->add + root->add) % mod;
		}
		root->add = 0;
	}
}

void update(Node* root, int l, int r, int l1, int r1, int val) {
	//cout << l << ' ' << r << endl;
	push(root, l, r);
	if(l > r1 || l1 > r) {
		return;
	}
	if(l1 <= l && r <= r1) {
		root->sub = val;
		push(root, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(root->l, l, mid, l1, r1, val);
	update(root->r, mid + 1, r, l1, r1, val);
	root->sum = (root->l->sum + root->r->sum) % mod;
}

void fill0(Node* root, int l, int r, int l1, int r1) {
	push(root, l, r);
	if(l > r1 || l1 > r) return;
	if(l1 <= l && r <= r1) {
		root->fill0 = true;
		push(root, l, r);
		return;
	}
	int mid = (l + r) / 2;
	fill0(root->l, l, mid, l1, r1);
	fill0(root->r, mid + 1, r, l1, r1);
	root->sum = (root->l->sum + root->r->sum) % mod;
}

int get_val(Node* root, int l, int r, int l1, int r1) {
	push(root, l, r);
	if(l1 > r || l > r1) {
		return 0;
	}
	if(l1 <= l && r <= r1) {
		return root->sum;
	}
	int mid = (l + r) / 2;
	return (get_val(root->l, l, mid, l1, r1) + get_val(root->r, mid + 1, r, l1, r1)) % mod;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    precalc();
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    Node* root = new Node();
    root->sum = MX % mod;
	fill0(root, 1, MX, a[0] + 1, MX);
    for(int i = 1; i < n; i++) {
    	update(root, 1, MX, 1, a[i], root->sum);
		fill0(root, 1,MX, a[i] + 1, MX);
    }
    //cout << root->r->sum << endl;
    //cout << get_val(root, 1, 1000000000, 1, 1) << endl;
    cout << root->sum;
}