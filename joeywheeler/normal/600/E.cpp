#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> u[100005];
int c[100005];
int t[100005];
int mx, T;
long long st;
long long ans[100005];
int col[100005];

int ts[100005];

void clr() {
	mx = 0; st = 0;
	T++;
}

void inc(int i) {
	if (t[i] != T) {
		t[i] = T;
		c[i] = 0;
	}
	c[i]++;
	if (c[i] > mx) {
		mx = c[i];
		st = i;
	} else if (c[i] == mx) {
		st += i;
	}
}

void go(int i, int p) {
	ts[i] = 1;
	for (int j : u[i]) if (j != p) {
		go(j,i);
		ts[i] += ts[j];
	}
}

void go3(int i, int p) {
	inc(col[i]);
	for (int j : u[i]) if (j != p) go3(j,i);
}

void go2(int i, int p) {
	int mxc = -1;
	for (int j : u[i]) if (j != p) {
		if (mxc == -1 || ts[j] > ts[mxc]) mxc = j;
	}
	for (int j : u[i]) if (j != p && j != mxc) {
		go2(j,i);
		clr();
	}
	if (mxc != -1) go2(mxc,i);
	for (int j : u[i]) if (j != p && j != mxc) {
		go3(j,i);
	}
	inc(col[i]);
	ans[i] = st;
}

int main() {
	scanf("%d", &n);
	FO(i,1,n+1) scanf("%d", col+i);
	FO(i,0,n-1) {
		int x, y; scanf("%d%d", &x, &y);
		u[x].push_back(y);
		u[y].push_back(x);
	}
	go(1,0);
	go2(1,0);
	FO(i,1,n+1) printf("%lld%c", ans[i], " \n"[i==n]);
}