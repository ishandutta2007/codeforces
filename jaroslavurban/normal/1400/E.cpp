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

const int N=5030,inf=1e9;
int dp[N][N]; // pos, prev sz idx;
int n,m;
int a[N];
int idx[N],sz[N];
map<int,int>sss;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)sz[i]=a[i];
	sort(sz,sz+n);
	m=unique(sz,sz+n)-sz+1;
	for(int i=0;i<m-1;++i)sss[sz[i]]=i+1;
	for(int i=0;i<n;++i)idx[i]=sss[a[i]];
	for(int i=m;i>0;--i)sz[i]=sz[i-1];
	sz[0]=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<=n;++i)
		for(int j=m-1;j>=0;--j){
			dp[i+1][0]=min(dp[i+1][0],dp[i][j]+!!sz[idx[i]]+sz[j]); // delete all	
			if(idx[i]>=j){
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1); // lower myself
//				if(!i)cerr<<idx[i]<<endl;
				dp[i+1][idx[i]]=min(dp[i+1][idx[i]],dp[i][j]); // enhance everyone
				dp[i][0]=min(dp[i][0],dp[i][j]+sz[idx[i]]); // kill everyone slowly
			}
				
			if(idx[i]<=j){
				dp[i+1][idx[i]]=min(dp[i+1][idx[i]],dp[i][j]+sz[j]-sz[idx[i]]); // make them smaller
				dp[i+1][0]=min(dp[i+1][0],dp[i][j]+sz[j]); // delete all
			}

		}

	cout<<dp[n][0]<<endl;
}