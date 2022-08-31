#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 1000005;

int main(){
	int t; cin >> t;
	while(t--){
		lint r, g, b; cin >> r >> g >> b;
		lint tot = (r + g + b + 1) / 2;
		puts(max({r, g, b}) <= tot ? "Yes" : "No");
	}
}