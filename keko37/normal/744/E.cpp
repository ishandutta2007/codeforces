#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 35;
const int MAXS = 100005;

llint n, b1=31337, b2=1299721, p1=1000000007, p2=1000000011, sol;
string s[MAXN];
int len[MAXN], bio[MAXS];
llint h1[MAXN] [MAXS], h2[MAXN] [MAXS];
llint pot1[MAXS], pot2[MAXS];
vector <int> c[MAXN], v[MAXS];

llint sub (llint a, llint b, llint mod) {
	if (a-b<0) return a-b+mod; return a-b;
}

llint get_hash1 (int ind, int a, int b) {
	if (a==0) return h1[ind] [b];
	return sub(h1[ind] [b], pot1[b-a+1]*h1[ind] [a-1]%p1, p1);
}

llint get_hash2 (int ind, int a, int b) {
	if (a==0) return h2[ind] [b];
	return sub(h2[ind] [b], pot2[b-a+1]*h2[ind] [a-1]%p2, p2);
}

int isti (int ind1, int a1, int b1, int ind2, int a2, int b2) {
	return get_hash1(ind1, a1, b1)==get_hash1(ind2, a2, b2) && get_hash2(ind1, a1, b1)==get_hash2(ind2, a2, b2);
}

void precompute () {
	int cnt=0;
	for (int i=0; i<n; i++) {
		len[i]=s[i].size();
		for (int j=0; j<len[i]; j++) {
			cnt++;
			c[i].push_back(cnt);
			h1[i] [j]=(s[i] [j] + b1*(j==0?0:h1[i] [j-1]))%p1;
			h2[i] [j]=(s[i] [j] + b2*(j==0?0:h2[i] [j-1]))%p2;
			pot1[j]=(j==0?1:b1*pot1[j-1])%p1;
			pot2[j]=(j==0?1:b2*pot2[j-1])%p2;
		}
	}
}


void gen (int a, int b) {
	for (int i=0; i<MAXS; i++) {
		v[i].clear();
	}
	for (int i=a; i<=b; i++) {
		v[0].push_back(c[i] [0]);
		for (int j=0; j<len[i]; j++) {
			for (int k=a; k<=b; k++) {
				if (len[i]-j>len[k]) {
					if (isti(i, j, j+len[k]-1, k, 0, len[k]-1)) {
						v[c[i] [j]].push_back(c[i] [j+len[k]]);
					}
				} else if (len[i]-j<len[k]) {
					if (isti(i, j, len[i]-1, k, 0, len[i]-1-j)) {
						v[c[i] [j]].push_back(c[k] [len[i]-j]);
					}
				} else {
					if (j!=0 && isti(i, j, len[i]-1, k, 0, len[k]-1)) {
						v[c[i] [j]].push_back(0);
					}
				}
			}
		}
	}
}

int dfs (int cvor) {
	bio[cvor]=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (bio[sus]==1) return 1;
		if (bio[sus]==0 && dfs(sus)) return 1;
	}
	bio[cvor]=2;
	return 0;
}

int ciklus () {
	memset(bio, 0, sizeof bio);
	for (int i=0; i<MAXS; i++) {
		if (bio[i]==0 && dfs(i)) return 1;
	}
	return 0;
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	precompute();
	int lef=0;
	for (int i=0; i<n; i++) {
		if (lef<i) lef=i;
		while (lef<n) {
			gen(i, lef);
			if (ciklus()) break;
			lef++;
		}
		if (i==lef) continue;
		sol+=lef-i;
	}
	cout << sol;
	return 0;
}