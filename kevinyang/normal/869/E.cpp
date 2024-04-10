#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
vector<vector<int>>bit(3005,vector<int>(3005));
void update(int x, int y, int val){
	for(int a = x; a<2600; a+=a&-a){
		for(int b = y; b<2600; b+=b&-b){
			bit[a][b]^=val;
		}
	}
}
int query(int x, int y){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		for(int b = y; b>0; b-=b&-b){
			sum^=bit[a][b];
		}
	}
	return sum;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,q;
	cin >> n >> m >> q;
	map<pair<pair<int,int>,pair<int,int>>,int>hm;
	while(q--){
		int t;
		cin >> t;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(t==1){
			int v = rng();
			//assert(v>0);
			hm[{{a,b},{c,d}}] = v;
			update(a,b,v);
			update(c+1,b,v);
			update(a,d+1,v);
			update(c+1,d+1,v);
		}
		else if(t==2){
			int v = hm[{{a,b},{c,d}}];
			assert(v!=0);
			update(a,b,v);
			update(c+1,b,v);
			update(a,d+1,v);
			update(c+1,d+1,v);
			hm[{{a,b},{c,d}}] = 0;
		}
		else{
			int v = query(a,b); int v2 = query(c,d);
			if(v==v2)cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}