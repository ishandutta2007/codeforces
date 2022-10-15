#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;
//const int N = 300;
const int l = 40;

struct vertex {
	bool isTerminal;
	vertex * right;
	vertex * left;
	vertex() {
		isTerminal = false;
		right = left = NULL;
	}
	void add(const vector<int>& s, int pos = 0) {
		if (pos == s.size()) {
			isTerminal = true;
			return;
		}
		if (s[pos] == 0) {
			if (left == NULL)
				left = new vertex;
			left->add(s, pos + 1);
		}
		else {
			if (right == NULL)
				right = new vertex;
			right->add(s, pos + 1);
		}
	}
	ll find(const vector<int>& s, int pos = 0) {
		if (pos == s.size())
			return 0;
		ll res = 0;
		if (s[pos] == 1) {
			if (left != NULL) {
				res += (ll)1 << (s.size() - 1 - pos);
				res += left->find(s, pos + 1);
			}
			else {
				res += right->find(s, pos + 1);
			}
		}
		else {
			if (right != NULL) {
				res += (ll)1 << (s.size() - 1 - pos);
				res += right->find(s, pos + 1);
			}
			else {
				res += left->find(s, pos + 1);
			}
		}
		return res;
	}
};

struct trie {
	vertex root;
	vector<int> convert(ll x) {
		int ind = l;
		vector<int> s(l, 0);
		while (x) {
			--ind;
			if (x & 1) 
				s[ind] = 1;
			x >>= 1;
		}
		return s;
	}
	void add(ll x, int pos = 0) {
		root.add(convert(x), pos);
	}
	ll find(ll x, int pos = 0) {
		return root.find(convert(x), pos);
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	trie bor;
	cin >> n;
	vector<ll> data(n);
	ll res = 0;
	ll cur = 0, suf = 0;
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		cur = cur ^ data[i];
	}
	res = cur;
	bor.add(0);
	for (int i = n - 1; i >= 0; --i) {
		cur = cur ^ data[i];
		suf = suf ^ data[i];
		vector<int> s(l, 0);
		bor.add(suf);
		res = max(res, bor.find(cur));
	}
	cout << res << endl;

	return 0;
}