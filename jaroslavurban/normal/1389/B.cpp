#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=100010,M=6;
int a[N];
int dp[N][M][2];
int n,k,z;
int solvedp(int idx,int l,bool b){
	if(~dp[idx][l][b])return dp[idx][l][b];
	int total=idx+2*(z-l);
	if(total==k)return dp[idx][l][b]=a[idx];
	int mx=0;
	if(idx<n-1)mx=max(mx,solvedp(idx+1,l,0));
	if(idx>0&&!b&&l)mx=max(mx,solvedp(idx-1,l-1,1));
	return dp[idx][l][b]=mx+a[idx];
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>k>>z;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=z;++j)
				for(int k=0;k<2;++k)
					dp[i][j][k]=-1;
		for(int i=0;i<n;++i)cin>>a[i];
		int res=solvedp(0,z,0);
		cout<<res<<'\n';
	}
}