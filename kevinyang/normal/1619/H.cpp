#include <bits/stdc++.h>
using namespace std;
int sq = 350;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>p(n+1);
	vector<int>p2(n+1);
	for(int i = 1; i<=n; i++){
		cin >> p[i];
		p2[p[i]] = i;
	}
	vector<int>f(n+1);
	for(int i = 1; i<=n; i++){
		int cur = i;
		for(int j = 0; j<sq; j++){
			cur = p[cur];
		}
		f[i] = cur;
	}
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int x,y;
			cin >> x >> y;
			swap(p[x],p[y]);
			p2[p[x]] = x;
			p2[p[y]] = y;
			if(true){
				int cur = x; int cur2 = x;
				for(int i = 0; i<sq; i++){
					cur = p2[cur];
				}
				for(int j = 0; j<sq+5; j++){
					f[cur] = cur2;
					cur = p[cur]; cur2 = p[cur2];
				}
			}
			if(true){
				int cur = y; int cur2 = y;
				for(int i = 0; i<sq; i++){
					cur = p2[cur];
				}
				for(int j = 0; j<sq+5; j++){
					f[cur] = cur2;
					cur = p[cur]; cur2 = p[cur2];
				}
			}
		}
		else{
			int i,v;
			cin >> i >> v;
			int cur = i;
			for(int j = 0; j<v/sq; j++){
				cur = f[cur];
			}
			for(int j = 0; j<v%sq; j++){
				cur = p[cur];
			}
			cout << cur << "\n";
		}
	}
	return 0;
}