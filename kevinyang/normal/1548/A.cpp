#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	vector<int>deg(n+1);
	for(int i = 1; i<=m; i++){
		int x,y;
		cin >> x >> y;
		if(x>y)swap(x,y);
		deg[x]++;
		if(deg[x]==1)cnt++;
	}
	int q;
	cin >> q;
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int x,y;
			cin >> x >> y;
			if(x>y)swap(x,y);
			deg[x]++;
			if(deg[x]==1)cnt++;
		}
		else if(cm==2){
			int x,y;
			cin >> x >> y;
			if(x>y)swap(x,y);
			deg[x]--;
			if(deg[x]==0)cnt--;
		}
		else{
			cout << n-cnt << "\n";
		}
	}
	return 0;
}