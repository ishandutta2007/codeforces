#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
int n,m;
int d[1009][1009],p[1009][1009],a[1009][1009];
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=2;i<=n;++i)d[i][0]=1e9,p[i][0]=0;
	for(int i=2;i<=m;++i)d[0][i]=1e9,p[0][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			d[i][j]=min(d[i-1][j],d[i][j-1])+(a[i][j]>0);
			p[i][j]=max(p[i-1][j],p[i][j-1])+(a[i][j]>0);
		}
	}
	if((n+m)%2==1&&d[n][m]<=(n+m-1)/2&&p[n][m]>=(n+m-1)/2)puts("YES");
	else puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 4
1 -1 1 1
-1 1 -1 1
1 -1 1 1

*/