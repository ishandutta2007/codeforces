#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct custom_map_node {
	char k;
	int v;
	custom_map_node* next;
} pool[6000005 * 3], *pool_free;

struct custom_map {
	custom_map_node* root;

	custom_map() : root(nullptr) {}

	bool count(char c) {
		for (auto p = root; p; p = p->next)
			if (p->k == c)
				return true;
		return false;
	}

	int& operator[] (char c) {
		for (auto p = root; p; p = p->next)
			if (p->k == c)
				return p->v;
		auto t = root;
		root = pool_free++;
		root->next = t;
		root->k = c;
		root->v = 0;
		return root->v;
	}
};

custom_map deepcopy(custom_map mp) {
	custom_map mp2;
	for (auto p = mp.root; p; p = p->next) {
		auto t = mp2.root;
		mp2.root = pool_free++;
		mp2.root->next = t;
		mp2.root->k = p->k;
		mp2.root->v = p->v;
	}
	return mp2;
}

template<class T>
struct cv_node {
	T x;
	cv_node* next;
};

cv_node<int> cvni_pool[6000005], *cvni_pool_free;
cv_node<int*> cvnpi_pool[1000005], *cvnpi_pool_free;

template<class T>
struct cviter {
	cv_node<T>* p;
	// TODO operatori
	T& operator* () const {
		return p->x;
	}

	cviter& operator++ () {
		p = p->next;
		return *this;
	}

	bool operator== (const cviter& b) const {
		return p == b.p;
	}

	bool operator!= (const cviter& b) const {
		return p != b.p;
	}
};

template<class T>
cv_node<T>* new_cv_node();

template<>
cv_node<int>* new_cv_node() {
	return cvni_pool_free++;
}

template<>
cv_node<int*>* new_cv_node() {
	return cvnpi_pool_free++;
}

template<class T>
struct custom_vector {
	cv_node<T>* root;

	custom_vector() : root(nullptr) {}

	cviter<T> begin() {
		return {root};
	}

	cviter<T> end() {
		return cviter<T>{nullptr};
	}

	void push_back(T x) {
		auto t = root;
		root = new_cv_node<T>();
		root->next = t;
		root->x = x;
	}
};

struct node {
	int len, link, dp;
	custom_map next;
	custom_vector<int> inv;
	custom_vector<int*> pitanja;
	// vector<int> inv;
	// vector<int*> pitanja;
} b[6000005]; int sz = 0;

int prefiks[3000005];

vector<int> automat(const string& s, int k) {
	int last = sz++;
	b[last].link = -1;
	for (char c : s) {
		int curr = sz++, p = last;
		b[curr].len = b[last].len + 1;
		if (b[curr].len <= k)
			b[curr].dp = 1;
		prefiks[b[curr].len] = curr;
		for (; p != -1 && !b[p].next.count(c); p = b[p].link)
			b[p].next[c] = curr;
		if (p == -1) {
			b[curr].link = 0;
		} else {
			int q = b[p].next[c];
			if (b[q].len == b[p].len + 1) {
				b[curr].link = q;
			} else {
				int clone = sz++;
				b[clone].len = b[p].len + 1;
				b[clone].next = deepcopy(b[q].next);
				b[clone].link = b[q].link;
				for (; p != -1 && b[p].next[c] == q; p = b[p].link)
					b[p].next[c] = clone;
				b[q].link = b[curr].link = clone;
			}
		}
		last = curr;
	}

	vector<int> v(sz);
	iota(v.begin(), v.end(), 0);
	sort(v.begin(), v.end(), [&](int x, int y) {
		return b[x].len < b[y].len;
	});
	// mozemo i da ocistimo next, koji ce nam djavo
	for (int i=0; i<sz; i++)
		b[i].next = {};
	return v;
}

string s, p[100005], u;
int n, q;
vector<int> odgovori[100005];

vector<pair<int, int>> stek;

void dfs(int x) {
	stek.push_back({b[x].len, x});
	// resi pitanja
	for (auto ptr : b[x].pitanja)
		*ptr = lower_bound(stek.begin(), stek.end(), make_pair(*ptr, -1))->second;
	for (int y : b[x].inv) {
		dfs(y);
		b[x].dp += b[y].dp;
	}
	stek.pop_back();
}

int faktor(const string& s) {
	int n = s.size();
	vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(r-i, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i+z[i] > r)
			l = i, r = i+z[i];
	}
	for (int x=1; x<n; x++)
		if (n%x == 0 && z[x] == n-x)
			return x;
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pool_free = pool;
	cvni_pool_free = cvni_pool;
	cvnpi_pool_free = cvnpi_pool;

	cin >> s >> q;
	u = s;
	for (int i=0; i<q; i++) {
		cin >> p[i];
		u += p[i] + p[i];
	}
	auto v = automat(u, s.size());
	for (int x : v)
		if (x)
			b[b[x].link].inv.push_back(x);

	for (int i=0, z=s.size(); i<q; i++) {
		int m = p[i].size();
		odgovori[i].assign(m, m);
		for (int j=0; j<m; j++) {
			int x = prefiks[z+j+m];
			b[x].pitanja.push_back(&odgovori[i][j]);
		}
		z += 2*m;
	}

	dfs(0);

	for (int i=0; i<q; i++) {
		int m = faktor(p[i]), z = 0;
		for (int j=0; j<m; j++) {
			int x = odgovori[i][j];
			z += b[x].dp;
		}
		cout << z << '\n';
	}
}