#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

struct disj{
	int pa[10005];
	void init(int n){
		for(int i=1; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p =find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int main(){
	int n;
	cin >> n;
	disj.init(n);
	int cnt = n;
	for(int i=1; i<=n; i++){
		int p;
		cin >> p;
		if(disj.uni(i, p)) cnt--;
	}
	cout << cnt;

}