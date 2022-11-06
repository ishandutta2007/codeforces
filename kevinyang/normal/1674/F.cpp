#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>bit(1005,vector<int>(1005));
void update(int x, int y, int val){
	for(int a = x; a<1005; a+=a&-a){
		for(int b = y; b<1005; b+=b&-b){
			bit[a][b]+=val;
		}
	}
}
int query(int x, int y){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		for(int b = y; b>0; b-=b&-b){
			sum+=bit[a][b];
		}
	}
	return sum;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,q;
	cin >> n >> m >> q;
	int total = 0;
	vector<vector<int>>mp(n+1,vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			if(s[j-1]=='*')mp[i][j] = 1;
			if(mp[i][j]){
				update(i,j,1);
				total++;
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		mp[x][y]^=1;
		if(mp[x][y]==0){
			update(x,y,-1);
			total--;
		}
		else{
			update(x,y,1);
			total++;
		}
		int len = total/n;
		int rem = total%n;
		int v = query(n,len)+query(rem,len+1)-query(rem,len);
		cout << total-v << "\n";
	}

	return 0;
}