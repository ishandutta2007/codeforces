#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

int n, m, gap = 1e9;

int main(){
	cin >> n >> m;
	while(m--){
		int l, r;
		scanf("%d %d",&l,&r);
		gap = min(gap, r-l+1);
	}
	printf("%d\n", gap);
	for(int i=1; i<=n; i++) printf("%d ", i % gap);
}