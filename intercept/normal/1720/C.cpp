#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=509;
int a[M][M];
void work(){
	int n,m,t=0;
	scanf("%d%d",&n,&m);
	bool f1=0,f2=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)scanf("%1d",&a[i][j]),t+=a[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]==0)f1=1;
			if(i>1&&a[i][j]==0&&a[i-1][j]==0)f2=1;
			if(j>1&&a[i][j]==0&&a[i][j-1]==0)f2=1;
			if(i>1&&j<m&&a[i][j]==0&&a[i-1][j+1]==0)f2=1;
			if(i>1&&j>1&&a[i][j]==0&&a[i-1][j-1]==0)f2=1;
		}
	}
	if(f2==0)t--;
	if(f1==0)t--;
	printf("%d\n",t);
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}