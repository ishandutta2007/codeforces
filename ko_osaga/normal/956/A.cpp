#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 1000005;

struct disj{
	int par[105];
	void init(int n){
		iota(par, par + 105, 0);
	}
	int find(int x){
		return par[x] = (par[x] == x ? x : find(par[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		par[q] = p; return 1;
	}
}disj;
int n, m;
string s[105];

int main(){
	cin >> n >> m;
	disj.init(0);
	for(int i=0; i<n; i++){
		cin >> s[i];
		for(int j=0; j<m; j++){
			if(s[i][j] == '#') disj.uni(i, j + n);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j] != '#' && disj.find(i) == disj.find(j + n)){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
}