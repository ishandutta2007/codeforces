#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 300005;
const llint INF = 1000000000000LL;

llint n, sol;
llint p[MAXN];
char c[MAXN];
vector <llint> v[200];

void rjesi () {
	int lef, rig;
	llint maxi;
	for (int i=0; i<v['G'].size()-1; i++) {
		llint l=v['G'] [i], r=v['G'] [i+1];
		llint curr=0;
		for (char z='R'; ; z='B') {
			lef=lower_bound(v[z].begin(), v[z].end(), l)-v[z].begin();
			rig=upper_bound(v[z].begin(), v[z].end(), r)-v[z].begin()-1;
			if (0<=lef && lef<v[z].size() && 0<=rig && rig<v[z].size() && lef<=rig && l<=v[z] [lef] && v[z] [rig]<=r) {
				maxi=v[z] [lef]-l;
				for (int j=lef+1; j<=rig; j++) {
					maxi=max(maxi, v[z] [j]-v[z] [j-1]);
				}
				maxi=max(maxi, r-v[z] [rig]);
				curr+=r-l-maxi;
			}
			if (z=='B') break;
		}
		sol+=min(r-l+curr, 2*(r-l));
	}
	sol+=v['G'] [v['G'].size()-2]-v['G'] [1]-2*INF;
}

int main () {
	v['G'].push_back(-INF);
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%I64d", &p[i]);
		cin >> c[i];
		v[c[i]].push_back(p[i]);
	}
	v['G'].push_back(INF);
	if (v['G'].size()==2) {
		if (v['R'].size()>0) sol+=v['R'].back()-v['R'] [0];
		if (v['B'].size()>0) sol+=v['B'].back()-v['B'] [0];
		cout << sol;
		return 0;
	}
	rjesi();
	cout << sol;
	return 0;
}