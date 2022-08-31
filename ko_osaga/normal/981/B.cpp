#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<lint, lint>;

map<int, int> mp;

int main(){
	for(int i=0; i<2; i++){
		int x; scanf("%d",&x);
		while(x--){
			int p, q;
			scanf("%d %d",&p,&q);
			mp[p] = max(mp[p], q);
		}
	}
	lint ans = 0;
	for(auto &i : mp) ans += i.second;
	cout << ans << endl;
}