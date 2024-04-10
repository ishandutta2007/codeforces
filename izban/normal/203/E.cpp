#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

struct robot {
	int c,f,l,p;
	bool operator< (const robot &r) {
		return f<r.f || f==r.f && c>r.c || f==r.f && c==r.c && l>r.l || f==r.f && c==r.c && l==r.l && p<r.p;
	}
	robot () {}
};

const int maxn=100100;

int n,d,s,ans=0,anss=2000000000;
ll oo=0LL;
vector<robot> a,b;

void euristic1() {
	int S=s, k=0;
	for (int i=0; i<a.size(); i++) {
		if (S-a[i].f>=0) {
			S-=a[i].f;
			k++;
		}
	}
	if (k>ans || k==ans && s-S<anss) {
		ans=k;
		anss=s-S;
	}
}

void euristic2() {
	int S=s, cur=-1;
	ll k=0;
	for (int i=0; i<a.size(); i++) {
		if (a[i].c>0 && a[i].f<=S) {
			cur=i;
			S-=a[i].f;
			break;
		}
	}
	if (cur==-1) return;
	k+=oo+1;
	for (int i=0; i<a.size(); i++) if (cur!=i) {
		if (S-a[i].f>=0 && k<n) {
			S-=a[i].f;
			k++;
		}
	}
	k=min(k,(ll)n);
	if (k>ans || k==ans && s-S<anss) {
		ans=k;
		anss=s-S;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> d >> s; 
	for (int i=0; i<n; i++) {
		robot x; x.p=i;
		cin >> x.c >> x.f >> x.l;
		if (x.l>=d) a.push_back(x);
		else b.push_back(x);
		if (x.c>0) oo+=x.c;
	}
	sort(a.begin(),a.end());
	euristic1();
	euristic2();
	cout << ans << ' ' << anss;
	return 0;
}