#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

const int MAXN = 400005;
const int LIM = 17000000;
const int SIZ = 1000000005;

int n, m, pot=1, cnt=1;
int t[LIM], lef[LIM], rig[LIM], par[LIM];
int a[MAXN], b[MAXN], val[MAXN], eat[MAXN], cord[MAXN];
long long len[MAXN];

set < pair <pair <int, int>, int> > s;
set < pair <pair <int, int>, int> > :: iterator it;
multiset < pair <int, int> > muhe;
multiset < pair <int, int> > :: iterator it2;

int spoji (int ind1, int ind2) {
	if (a[ind1]<a[ind2]) return ind1; return ind2; 
}

void ubaci (int pos, int val) {
	int cvor=1, low=0, high=pot-1, mid;
	while (low<high) {
		mid=(low+high)/2;
		if (pos<=mid) {
			lef[cvor]=lef[cvor]?lef[cvor]:(++cnt);
			par[lef[cvor]]=cvor;
			cvor=lef[cvor];
			high=mid;
		} else {
			rig[cvor]=rig[cvor]?rig[cvor]:(++cnt);
			par[rig[cvor]]=cvor;
			cvor=rig[cvor];
			low=mid+1;
		}
	}
	t[cvor]=val;
	cvor=par[cvor];
	while (cvor) {
		t[cvor]=spoji(t[lef[cvor]], t[rig[cvor]]);
		cvor=par[cvor];
	}
}

int upit (int cvor, int from, int to, int low, int high) {
	if (cvor==0 || to<low || high<from) return 0; 
	if (from<=low && high<=to) return t[cvor];
	return spoji(upit(lef[cvor], from, to, low, (low+high)/2), upit(rig[cvor], from, to, (low+high)/2+1, high));
}

void povecaj (int ind, int k) {
	eat[ind]++;
	s.erase(make_pair(make_pair(b[ind], a[ind]), ind));
	it=s.lower_bound(make_pair(make_pair(b[ind], 0), 0));
	if (it==s.end() || (it->first).first!=b[ind]) ubaci(b[ind], 0); else ubaci(b[ind], it->second);
	len[ind]+=k;
	b[ind]=min((long long) SIZ, cord[ind]+len[ind]);
	s.insert(make_pair(make_pair(b[ind], a[ind]), ind));
	it=s.lower_bound(make_pair(make_pair(b[ind], 0), 0));
	ubaci(b[ind], it->second);
	it2=muhe.lower_bound(make_pair(a[ind], 0));
	if (it2!=muhe.end() && (it2->first)<=b[ind]) {
		int body=it2->second;
		muhe.erase(it2);
		povecaj(ind, body);
	}
}

int main () {
	a[0]=SIZ;
	while (pot<SIZ) pot*=2;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &cord[i], &len[i]);
		a[i]=cord[i];
		b[i]=min((long long) SIZ, cord[i]+len[i]);
		s.insert(make_pair(make_pair(b[i], a[i]), i));
		it=s.lower_bound(make_pair(make_pair(b[i], 0), 0));
		ubaci(b[i], it->second);
	}
	for (int i=0; i<m; i++) {
		int c, l;
		scanf("%d%d", &c, &l);
		int ind=upit(1, c, pot-1, 0, pot-1);
		if (ind && a[ind]<=c) povecaj(ind, l); else muhe.insert(make_pair(c, l));
	}
	for (int i=1; i<=n; i++) {
		printf("%d %lld\n", eat[i], len[i]);
	}
	return 0;
}