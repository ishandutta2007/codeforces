#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5][m+5],b[n+5][m+5];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>b[i][j];
	int tsum;
	for(int i=0;i<n;i++){
		tsum=0;
		for(int j=0;j<m;j++)if(a[i][j]!=b[i][j])tsum++;
		if(tsum%2==1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(int j=0;j<m;j++){
		tsum=0;
		for(int i=0;i<n;i++)if(a[i][j]!=b[i][j])tsum++;
		if(tsum%2==1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}