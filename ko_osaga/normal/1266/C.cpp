#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 10005;

int main(){
	int n, m; cin >> n >> m;
	if(n == 1 && m == 1){
		puts("0");
		return 0;
	}
	if(n == 1){
		for(int i=1; i<=m; i++) printf("%d ", i + 1);
		return 0;
	}
	if(m == 1){
		for(int i=1; i<=n; i++) printf("%d\n", i + 1);
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", i * (n + j));
		}
		puts("");
	}
}