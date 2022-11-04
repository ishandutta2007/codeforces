#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t[11][101][101];
ll n,q,c;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q>>c;
	for(int i=0;i<n;++i) {
		ll x,y,s;
		cin>>x>>y>>s;
		t[s][x][y]++;
	}
	
	for(int i=0;i<=c;++i) {
		for(int j=0;j<101;++j) {
			for(int k=0;k<101;++k) {
				t[i][j][k]+=(j>0?t[i][j-1][k]:0)+(k>0?t[i][j][k-1]:0)-(j>0&&k>0?t[i][j-1][k-1]:0);
			}
		}
	}
	
	while(q--) {
		int temp,x1,y1,x2,y2;
		cin>>temp>>x1>>y1>>x2>>y2;
		ll ans=0;

		for(int i=0;i<=c;++i) {
			ll cnt=t[i][x2][y2]-(x1>0?t[i][x1-1][y2]:0)-(y1>0?t[i][x2][y1-1]:0)+(x1>0&&y1>0?t[i][x1-1][y1-1]:0);
			ans+=cnt*((temp+i)%(c+1));
		}

		cout<<ans<<"\n";
	}
	
	return 0;
}