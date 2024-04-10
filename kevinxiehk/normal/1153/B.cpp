#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,h;
	cin>>n>>m>>h;
	int fr[m+3],l[n+3],top[n+3][m+3];
	for(int i=0;i<m;i++)cin>>fr[i];
	for(int i=0;i<n;i++)cin>>l[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>top[i][j];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)if(top[j][i]!=0&&l[j]>=fr[i]&&l[j]!=0)top[j][i]=fr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)if(top[i][j]!=0&&fr[j]>=l[i]&&fr[j]!=0)top[i][j]=l[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<top[i][j];
			if(j==m-1)cout<<endl;
			else cout<<" ";
		}
	}
	return 0;
}