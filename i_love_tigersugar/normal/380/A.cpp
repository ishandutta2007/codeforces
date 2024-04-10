#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
struct change {
	int t,l,c;
	change() {
		t=0;l=0;c=0;
	}
	void input(void) {
		cin >> t >> l;
		if (t>1) cin >> c;
	}
	ll val(void) const {
		if (t==1) return (1);
		return (1LL*l*c);
	}
};
ll len[MAX];
change a[MAX];
vector<int> v;
int m,n;
void buildstr(void) {
	cin >> m;
	FOR(i,1,m) {
		a[i].input();
		len[i]=len[i-1]+a[i].val();		
	}
	v.push_back(0);
	int id=1;
	while (v.size()<MAX && id<=m) {
		if (a[id].t==1) v.push_back(a[id].l);
		else {
			REP(j,a[id].c) FOR(k,1,a[id].l) {
				if (v.size()>=MAX) return;
				v.push_back(v[k]);
			}
		}
		id++;
	}
}
int answer(ll pos) {
	int id=lower_bound(len,len+m+1,pos)-len;
	if (a[id].t==1) return (a[id].l);
	else {
		ll t=pos-len[id-1];
		return (v[(t-1)%a[id].l+1]);
	}
}
void process(void) {
	cin >> n;
	REP(i,n) {
		ll t; cin >> t;
		if (i>0) cout << " ";
		cout << answer(t);		
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	buildstr();
	process();
	return 0;
}