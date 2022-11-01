// In the name of God
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#define sqr(a) (a)*(a)
using namespace std;

template <typename T>
T next_int() {
	T x = 0, p = 1;
	char ch;
	do { ch = getchar(); } while(ch <= ' ');
	if(ch == '-') {
		p = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return p * x;
}
	
const int max_int = (int)1e9 + 227 + 1;
const int max_n = (int)2e5 + 227 + 1;	
const int mod = (int)1e9 + 7;

vector<int> b;
vector<vector<int> > a;
int k[max_n];
int d[max_n];

void ge(int v, int pr = -1) {
	k[v] = b[v];
	d[v] = 1;
	for(int i = 0; i < a[v].size(); i++) {
		if(a[v][i] != pr) {
			ge(a[v][i], v);
			k[v] += k[a[v][i]];
			d[v] += d[a[v][i]];
		}
	}
}

int K;

vector<int> ans;

void go(int v, int pr = -1) {
	if(pr != -1) {
		b[v] = 1 - b[v];
		if(b[v]) K++;
		if(!b[v]) K--;
	}

	ans.push_back(v);

	for(int i = 0; i < a[v].size(); i++) {
		if(a[v][i] == pr) continue;

		if(k[a[v][i]] == d[a[v][i]]) continue;

		go(a[v][i], v);

		b[v] = 1 - b[v];

		if(!b[v]) K--;
		if(b[v]) K++;
	}

	if(b[v] == 0) {
		if(pr == -1) {
			int ve = a[v][0];
			ans.push_back(ve);
			ans.push_back(v);
			ans.push_back(ve);

			for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
			puts("");
			exit(0);
		}

		b[v] = 1 - b[v];
		b[pr] = 1 - b[pr];
		K++;
		if(!b[pr]) K--;
		if(b[pr]) K++;

		ans.push_back(pr);
		ans.push_back(v);
	}

	if(K == a.size()) {
		for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
		puts("");

		exit(0);
	}

	if(pr != -1) ans.push_back(pr);
}

int main() {
//	freopen(".in", "r", stdin);
    srand(time(0));

    int n = next_int<int>();

    b.resize(n);
    for(int i = 0; i < n; i++) {
    	b[i] = (next_int<int>() == 1);
    	K += b[i];
    }

    int m = n - 1;
    a.resize(n);
    while(m--) {
    	int x = next_int<int>() - 1;
    	int y = next_int<int>() - 1;

    	a[x].push_back(y);
    	a[y].push_back(x);
    }

    ge(0);
    go(0);

	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
	puts("");
}