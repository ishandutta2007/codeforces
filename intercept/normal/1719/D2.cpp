#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n;
int a[M],dp[M];
map<int,int>mp;
void work(){
	mp.clear();
	cin>>n;
	mp[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]^=a[i-1];
		dp[i]=dp[i-1]+1;
		if(mp.count(a[i])){
			int l=mp[a[i]];
			dp[i]=min(dp[i],dp[l]+i-l-1);
		}
		mp[a[i]]=i;
	}
	cout<<dp[n]<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5 2
3 1 2 5 4
1 2
1 1
*/