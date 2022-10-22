#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1009;
int n,k;
int a[M][M],b[M*M],dp[M][M];
int lx[M*M],ly[M*M],rx[M*M],ry[M*M];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n*n;++i)lx[i]=ly[i]=n+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j],b[a[i][j]]++;
			int t=a[i][j];
			lx[t]=min(lx[t],i);
			ly[t]=min(ly[t],j);
			rx[t]=max(rx[t],i);
			ry[t]=max(ry[t],j);
		}
	}
	int sum=0;
	for(int i=1;i<=n*n;++i)if(b[i])sum++;
	if(sum==k){
		puts("0");
		return 0;
	}
	if(sum<k){
		cout<<k-sum<<endl;
		return 0;
	}
	if(k==1){
		puts("1");
		return 0;
	}
	for(int l=1;l<=n;++l){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)dp[i][j]=0;
		}
		for(int i=1;i<=n*n;++i){
			if(b[i]){
				if(rx[i]-lx[i]+1>l||ry[i]-ly[i]+1>l)continue;
				dp[rx[i]][ry[i]]++;
				dp[rx[i]][ly[i]+l]--;
				dp[lx[i]+l][ry[i]]--;
				dp[lx[i]+l][ly[i]+l]++;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				if(i<l||j<l)continue;
				if(dp[i][j]==sum-k||dp[i][j]==sum+1-k){
					puts("1");
					return 0;
				}
			}
		}
	}
	puts("2");
	return 0;
}
/*
3 5
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/