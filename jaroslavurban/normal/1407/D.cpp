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

 
const int N=300100,inf=1e9;
ll h[N];
int dp[N],n;
int low[N],maxlow=1;
int high[N],maxhigh=1;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>h[i];
	for(int i=0;i<n;++i)dp[i]=inf;
	dp[0]=0;
	for(int i=1;i<n;++i){
		int mnlow=inf;
		while(maxlow&&h[low[maxlow-1]]>h[i])mnlow=min(mnlow,dp[low[--maxlow]]);
		if(maxlow)mnlow=min(mnlow,dp[low[maxlow-1]]);
		if(!maxlow||h[low[maxlow-1]]<h[i])low[maxlow++]=i;
		else low[maxlow-1]=i;

		int mnhigh=inf;
		while(maxhigh&&h[high[maxhigh-1]]<h[i])mnhigh=min(mnhigh,dp[high[--maxhigh]]);
		if(maxhigh)mnhigh=min(mnhigh,dp[high[maxhigh-1]]);
		if(!maxhigh||h[high[maxhigh-1]]>h[i])high[maxhigh++]=i;
		else high[maxhigh-1]=i;
		dp[i]=min(mnlow,mnhigh)+1;
	}
	cout<<dp[n-1]<<endl;
}