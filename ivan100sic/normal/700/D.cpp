#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <list>
#include <cstdio>
#define BLOCK(x) ((x) >> 8)
using namespace std;

struct Query {
	int l, r, id;

	bool operator < (const Query& o) const {
		return BLOCK(l) < BLOCK(o.l) || (BLOCK(l) == BLOCK(o.l) && r < o.r);
	}
};

int N, QC;
Query Q[100005];
int A[100005];

void read() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", A + i);
	scanf("%d", &QC);
	for (int i = 1; i <= QC; i++) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].id = i;
	}
	sort(Q + 1, Q + QC + 1);
}

int FirstC[100005];
// map<int, int> Hist;
int Hist[100005];
bool Buka[100005];
int PL, PR;

int Active[400005], ActiveC;

inline void add(int x) {
	int v = ++FirstC[x];
	Hist[v]++;
	Hist[v - 1]--;
	if (Hist[v] > 0) Active[ActiveC++] = v;
}

inline void rem(int x) {
	int v = --FirstC[x];
	Hist[v]++;
	Hist[v + 1]--;
	if (Hist[v] > 0) Active[ActiveC++] = v;
}

inline void moveto(int tl, int tr) {
	while (PL > tl) {
		add(A[--PL]);
	}
	while (PL < tl) {
		rem(A[PL++]);
	}

	while (PR > tr) {
		rem(A[PR--]);
	}
	while (PR < tr) {
		add(A[++PR]);
	}
}

struct ljist_node {

	static ljist_node zenba[1024];
	static ljist_node* vugla;

	int first;
	int second;
	ljist_node* prev;
	ljist_node* next;

	static ljist_node* nov() {
		ljist_node* rez = vugla;
		vugla = vugla->next;
		return rez;
	}

	void oslobodi() {
		this->next = vugla;
		vugla = this;
	}

private:
	ljist_node() = default;
	ljist_node(const ljist_node&) = default;
	ljist_node& operator= (const ljist_node&) = default;
};

struct ljist_node_iterator {
	ljist_node* ptr;

	ljist_node* operator-> () {
		return ptr;
	}

	ljist_node_iterator(ljist_node* ptr = nullptr) : ptr(ptr) {}

	bool operator== (const ljist_node_iterator& o) const {
		return ptr == o.ptr;
	}

	ljist_node_iterator& operator++ () {
		ptr = ptr->next;
		return *this;
	}
};

ljist_node ljist_node::zenba[1024];
ljist_node* ljist_node::vugla = ljist_node::zenba;

void init_zenba() {
	for (int i = 0; i < 1023; i++) {
		ljist_node::zenba[i].next = ljist_node::zenba + i + 1;
	}
}

struct ljist {
	typedef ljist_node_iterator iterator;

	void pop_front() {
		if (_size == 1) {
			_front->oslobodi();
			_front = _back = nullptr;
		} else {
			_front = _front->next;
			_front->prev->oslobodi();
			_front->prev = nullptr;
		}
		--_size;
	}

	void push_back(const pair<int, int>& p) {
		if (_size == 0) {
			_front = _back = ljist_node::nov();
			_back->next = _back->prev = nullptr;
		} else {
			_back->next = ljist_node::nov();
			_back->next->prev = _back;
			_back = _back->next;
			_back->next = nullptr;
		}
		++_size;
		_back->first = p.first;
		_back->second = p.second;
	}
	
	iterator insert(iterator pos, const pair<int, int>& par) {
		ljist_node* p = ljist_node::nov();
		p->first = par.first;
		p->second = par.second;
		p->next = pos.ptr;
		
		if (p->next) {
			p->prev = p->next->prev;
		} else {
			p->prev = _back;
		}

		if (p->prev) p->prev->next = p;
		if (p->next) p->next->prev = p;

		if (!p->next) _back = p;
		if (!p->prev) _front = p;

		++_size;

		return p;
	}

	void clear() {
		while (_size > 0) pop_front();
	}

	iterator begin() { return _front; }
	iterator end() { return nullptr; }

	ljist_node& front() { return *_front; }

	~ljist() {
		clear();
	}

	size_t size() { return _size; }

	ljist() : _front(nullptr), _back(nullptr), _size(0) {}

private:
	ljist_node* _front;
	ljist_node* _back;
	size_t _size;
};

ljist red;
ljist::iterator ubac;

void iskopiraj() {
	red.clear();
	int lim = ActiveC;
	ActiveC = 0;
	for (int i = 0; i < lim; i++) {
		if (Hist[Active[i]] > 0 && Active[i] > 0 && !Buka[Active[i]]) {
			Buka[Active[i]] = true;
			Active[ActiveC++] = Active[i];
		}
	}
	sort(Active, Active + ActiveC);
	for (int i = 0; i < ActiveC; i++) {
		red.push_back({ Active[i], Hist[Active[i]] });
		Buka[Active[i]] = false;
	}
}

int ubaci_c;

inline void ubaci(int broj, int multiplicitet) {
	while (1) {
		ubaci_c++;
		if (ubac->first == broj) {
			ubac->second += multiplicitet;
			return;
		} else {
			++ubac;
			if (ubac == red.end() || ubac->first > broj) {
				ubac = red.insert(ubac, { broj, multiplicitet });
				return;
			}
		}
	}
}

void pocisti() {
	if (red.front().second == 0) {
		red.pop_front();
	}
}

int resi() {
	iskopiraj();
	ubac = red.begin();
	int sol = 0;
	while (red.size() > 0 && (red.size() > 1 || red.front().second > 1)) {
		auto prvi = red.begin();
		if (prvi->second == 1) {
			auto drugi = ++red.begin();
			ubaci(prvi->first + drugi->first, 1);
			sol += prvi->first + drugi->first;
			red.pop_front();
			drugi->second--;
		} else {
			ubaci(prvi->first * 2, prvi->second / 2);
			sol += prvi->first * 2 * (prvi->second / 2);
			prvi->second -= 2 * (prvi->second / 2);
		}
		pocisti();
	}
	return sol;
}

int CC[100005];

void solve() {
	PL = 1;
	PR = 0;
	for (int i = 1; i <= QC; i++) {
		moveto(Q[i].l, Q[i].r);
		CC[Q[i].id] = resi();
	}
	for (int i = 1; i <= QC; i++) {
		printf("%d\n", CC[i]);
	}
}

int main() {
	init_zenba();
	//freopen("d.txt", "r", stdin);
	//freopen("out", "w", stdout);
	read();
	solve();
	//printf("ubaci = %d\n", ubaci_c);
	scanf("%d", &N);
	return 0;
}

/*

7
1 2 1 3 1 2 1
5
1 7
1 3
3 5
2 4
4 4

*/