#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 10005;

int main(){
	int tc; cin >> tc;
	while(tc--){
		lint n; cin >> n;
		if(n > 14 && n % 14 > 0 && n % 14 <= 6) puts("YES");
		else puts("NO");
	}
}