#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);
const int N=202;

int r[N],g[N],b[N];
ll dp[N][N][N];
int n,m,kk;
ll solvedp(int i,int j,int k){
	if(~dp[i][j][k])return dp[i][j][k];
	ll mx=0;
	if(i!=n&&j!=m)mx=max(mx,solvedp(i+1,j+1,k)+r[i]*g[j]);
	if(i!=n&&k!=kk)mx=max(mx,solvedp(i+1,j,k+1)+r[i]*b[k]);
	if(j!=m&&k!=kk)mx=max(mx,solvedp(i,j+1,k+1)+g[j]*b[k]);
	if(i!=n)mx=max(mx,solvedp(i+1,j,k));
	if(j!=m)mx=max(mx,solvedp(i,j+1,k));
	if(k!=kk)mx=max(mx,solvedp(i,j,k+1));
	return dp[i][j][k]=mx;
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>kk;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i)cin>>r[i];
	for(int i=0;i<m;++i)cin>>g[i];
	for(int i=0;i<kk;++i)cin>>b[i];
	sort(r,r+n);
	sort(g,g+m);
	sort(b,b+kk);
	reverse(r,r+n);
	reverse(g,g+m);
	reverse(b,b+kk);
	ll res=solvedp(0,0,0);
	cout<<res<<endl;
}