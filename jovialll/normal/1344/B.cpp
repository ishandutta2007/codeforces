#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,m,fir,i,j,las,existh,existl,li[N],h[N],l[N],r[N],dp[N],up,down;
char a[N][N];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>a[i][j];
			a[i][j]=a[i][j]=='#';
		}
	}
	for(i=1;i<=n;++i){
		fir=m+10,las=0;
		for(j=1;j<=m;++j)if(a[i][j])fir=min(fir,j),las=max(las,j);
		for(j=fir;j<=las;++j){
			if(!a[i][j]){cout<<"-1";return 0;}
		}
		l[i]=fir,r[i]=las;
	}
	for(i=1;i<=m;++i){
		up=n;down=0;
		for(j=1;j<=n;++j){
			if(a[j][i]){
				up=min(up,j);down=max(j,down);
			}
		}
		for(j=up;j<=down;++j){
			if(!a[j][i]){
				cout<<-1;
				return 0;
			}
		}
	}
	dp[1]=h[1]=l[1]<=r[1];
	for(j=l[1];j<=r[1];++j)li[j]=1;
	for(i=2;i<=n;++i){
		if(l[i]>r[i])dp[i]=dp[i-1];
		else dp[i]=dp[i-1]+1-(
		(l[i]>=l[i-1]&&l[i]<=r[i-1])||
		(r[i]>=l[i-1]&&r[i]<=r[i-1])||
		(l[i-1]>=l[i]&&l[i-1]<=r[i])||
		(r[i-1]>=l[i]&&r[i-1]<=r[i])),h[i]=1;
		for(j=l[i];j<=r[i];++j)li[j]=1;
	}
	
	for(i=1;i<=n;++i){
		if(h[i]==0){
			existh=1;
		}
	}
	for(i=1;i<=m;++i)if(li[i]==0)existl=1;
	//cout<<existh<<" "<<existl<<"\n";
	if(existh!=existl)cout<<-1;
	else cout<<dp[n];
	return 0;
}