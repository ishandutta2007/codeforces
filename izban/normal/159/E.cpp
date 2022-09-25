#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=100100;

struct cub {
	int c,s,o;
	bool operator< (const cub &a) {
		return c<a.c || c==a.c && s>a.s;
	}
} oo[maxn];

int n,m,cid1,cid2;
ll ans;
vector<cub> e[maxn];
vector<ll> d[maxn],vv,todelete;
set<int> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> oo[i].c >> oo[i].s, oo[i].o=i+1;
	sort(oo,oo+n);

	oo[n]=oo[n-1]; oo[n].c++; oo[n].s++; oo[n].o++;
	for (int i=0; i<n; i++) {
		e[m].push_back(oo[i]);
		m+=oo[i].c!=oo[i+1].c;
	}
	for (int i=0; i<m; i++) {
		d[i].push_back(0);
		for (int j=0; j<e[i].size(); j++) d[i].push_back(d[i].back()+e[i][j].s);
	}

	for (int i=0; i<m; i++) {
		s.insert(i);
		if (i && e[i].size()!=e[i-1].size()) vv.push_back(e[i].size());
		else if (!i) vv.push_back(e[i].size());
	}

	sort(vv.begin(),vv.end());
	//for (int i=0; i<vv.size(); i++) {
	for (int k=1; k<=vv.back(); k++) {
		int x=k,id1=-1,id2=-1;
		ll max1=0, max2=0;
		int xx=x;
		todelete.clear();
		for (set<int>::iterator it=s.begin(); it!=s.end(); it++) {
			if (d[*it].size()>x && d[*it][x]>max1) {
				max1=d[*it][x];
				id1=*it;
			}
			if (d[*it].size()<=x) 
				todelete.push_back(*it);
		}
		for (x=xx-1; x<=xx+1; x++) {
		for (set<int>::iterator it=s.begin(); it!=s.end(); it++) {
			if (d[*it].size()>x && d[*it][x]>max2 && *it!=id1) {
				max2=d[*it][x];
				id2=*it;
			}
		}
		}
		if (max2!=0 && ans<max1+max2) {
			ans=max1+max2;
			cid1=id1; cid2=id2;
		}
		for (int i=0; i<todelete.size(); i++) 
			s.erase(todelete[i]);
	}
	if (e[cid1].size()<e[cid2].size()) swap(cid1,cid2);


	cout << ans << endl;
	cout << e[cid2].size() + min(e[cid2].size()+1,e[cid1].size()) << endl;
	int i=0;
	while (1) {
		if (i<e[cid1].size()) cout << e[cid1][i].o << ' ';
		else break;
		if (i<e[cid2].size()) cout << e[cid2][i].o << ' ';
		else break;
		i++;
	}

	return 0;
}