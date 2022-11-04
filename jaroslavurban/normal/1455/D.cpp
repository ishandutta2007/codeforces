#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=505;
//int dp[N][N][N];
int a[N];
int n,x;

//int dfs(int idx,int last,int xcur){
//	if(idx==n)return 0;
//	if(~dp[idx][last][xcur])return dp[idx][last][xcur];
//	bool pos=true;
//	for(int i=idx;i<n;++i)if(i&&a[i]<a[i-1]){pos=false;break;}
//	if(pos)return dp[idx][last][xcur]=0;
//	for(int i=idx;i<n;++i){
//		if(a[i]>last)
//			return dp[idx][last][xcur]=dfs(i+1,xcur,a[i])+1;
//		if(i&&a[i]<a[i-1])
//			return dp[idx][last][xcur]=1e9;
//	}
//	assert(0);
//	return 0;
//}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>x;
//		for(int i=0;i<=n;++i)
//			for(int j=0;j<N;++j)
//				for(int k=0;k<N;++k)
//					dp[i][j][k]=-1;
		for(int i=0;i<n;++i)cin>>a[i];
		int su=n;
		for(int i=n-1;i>0;--i)if(a[i]>=a[i-1])--su;
		else break;
		if(su==1){
			cout<<0<<endl;
			continue;
		}
		int cur=0;
		int res=0;
		bool pos=true;
		while(cur<su){
			if(cur&&a[cur]<a[cur-1]){
//				cerr<<cur<<" "<<a[cur]<<" "<<a[cur-1]<<endl;
				pos=0;
				break;
			}
			if(a[cur]>x){
//				cerr<<cur<<endl;
				++res;
				int tmp=x;
				x=a[cur];
				a[cur]=tmp;
			}
			++cur;
		}
		if(pos)cout<<res<<endl;
		else cout<<-1<<endl;
//		int res=dfs(0,0,x);
//		if(res>=1e9)cout<<-1<<endl;
//		else cout<<res<<endl;
	}
}