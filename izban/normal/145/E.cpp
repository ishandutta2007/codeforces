#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

struct tree {
	int a4,a7,a47,a74;
	bool f;
};

const int maxn=1000000;

int n,m;
string c,s;
tree t[8*maxn];

void rev(int v) {
	swap(t[v].a4,t[v].a7);
	swap(t[v].a47,t[v].a74);
	t[v*2].f=!t[v*2].f;
	t[v*2+1].f=!t[v*2+1].f;
	t[v].f=false;
}

void recalc(int v) {
	if (t[v*2].f) rev(v*2);
	if (t[v*2+1].f) rev(v*2+1);
	t[v].a4=t[v*2].a4+t[v*2+1].a4;
	t[v].a7=t[v*2].a7+t[v*2+1].a7;
	t[v].a47=max(t[v*2].a4+t[v*2+1].a7,max(t[v*2].a47+t[v*2+1].a7,t[v*2].a4+t[v*2+1].a47));
	t[v].a74=max(t[v*2].a7+t[v*2+1].a4,max(t[v*2].a74+t[v*2+1].a4,t[v*2].a7+t[v*2+1].a74));
}

void build(int v, int tl, int tr) {
	if (tl==tr) {
		t[v].a4+=s[tl]=='4';
		t[v].a7+=s[tl]=='7';
		t[v].a47=1;
		t[v].a74=1;
		return;
	}
	int tm=(tl+tr)>>1;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	recalc(v);
}

int get(int v, int tl, int tr, int l, int r) {
	if (tl==l && r==tr) {
		return t[v].a47;
	}
}

void upd(int v, int tl, int tr, int l, int r) {
	if (l>r) return;
	if (t[v].f) rev(v);
	if (tl==l && tr==r) {
		rev(v);
		return;
	}
	int tm=(tl+tr)>>1;
	upd(v*2,tl,tm,l,min(r,tm));
	upd(v*2+1,tm+1,tr,max(l,tm+1),r);
	recalc(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin >> n >> m;
	cin >> s;
	build(1,0,n-1);
	for (int i=0; i<m; i++) {
		cin >> c;
		if (c=="count") 
			printf("%d\n",get(1,0,n-1,0,n-1));
		else {
			int l,r;
			cin >> l >> r;
			upd(1,0,n-1,l-1,r-1);
		}
	}
	return 0;
}