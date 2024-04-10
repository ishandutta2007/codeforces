#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

const int N=100100,inf=1e9;
int n,s,l,a[N],dp[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>s>>l;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<=n;++i)dp[i]=inf;
	dp[0]=0;
	set<pair<int,int>>pre,post;
	int j=0;
	for(int i=0;i<n;++i){
		pre.insert({a[i],i});
		while(pre.rbegin()->first-pre.begin()->first>s){
			pre.erase({a[j],j});
			post.erase({dp[j],j});
			++j;
		}
		if(i-j>=l-1)post.insert({dp[i-l+1],i-l+1});
		if(post.size())dp[i+1]=post.begin()->first+1;
		else dp[i+1]=inf;
	}
	if(dp[n]>=inf)cout<<-1<<endl;
	else cout<<dp[n]<<endl;
}