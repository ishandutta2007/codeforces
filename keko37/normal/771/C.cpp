#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, k, a, b, sol;
vector <int> v[MAXN];
llint val[MAXN];
llint r[MAXN] [7];
llint s[MAXN] [7];
llint rg[7], sg[7];

void dfs (int cvor, int par) {
	llint res=0;
	for (int i=0; i<v[cvor].size(); i++) {
		if (v[cvor] [i]==par) continue;
		int sus=v[cvor] [i];
		dfs(sus, cvor);
		res+=val[sus];
		for (int j=0; j<k-1; j++) {
			r[cvor] [j+1]+=r[sus] [j];
			s[cvor] [j+1]+=s[sus] [j];
		}
		r[cvor] [0]+=r[sus] [k-1];
		s[cvor] [0]+=s[sus] [k-1];
	}
	r[cvor] [0]++;
	s[cvor] [0]+=r[cvor] [0];
	for (int i=0; i<v[cvor].size(); i++) {
		if (v[cvor] [i]==par) continue;
		int sus=v[cvor] [i];
		for (int j=0; j<k-1; j++) {
			rg[j+1]=r[cvor] [j+1]-r[sus] [j];
			sg[j+1]=s[cvor] [j+1]-s[sus] [j];
		}
		rg[0]=r[cvor] [0]-r[sus] [k-1];
		sg[0]=s[cvor] [0]-s[sus] [k-1]-r[sus] [k-1];

		llint temp=0;
		
		llint rgsum=0;
		for (int j=k-1; j>=1; j--) {
			rgsum+=rg[j];
			res+=r[sus] [k-j]*rgsum;
			temp+=r[sus] [k-j]*rgsum;
		}
		rgsum+=rg[0];
		llint sgsum=0, rfsum=0, sfsum=0;
		for (int j=0; j<k; j++) {
			sgsum+=sg[j];
			rfsum+=r[sus] [j];
			sfsum+=s[sus] [j];
		}
		res+=(sgsum-rgsum)*rfsum+(rgsum+1)*sfsum;
	}
	val[cvor]=res;
}

int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n-1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cout << val[1]/2;
	return 0;
}