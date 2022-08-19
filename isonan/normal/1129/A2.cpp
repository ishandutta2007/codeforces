#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int n,a[100001],tot,m,b[100001],mn[100001],cnt[100001];
int dist(int x,int y){return (x<=y)?(y-x):(n-x+y);}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		int dis=dist(a[i],b[i]);
		if(!cnt[a[i]])mn[a[i]]=dis;
		else mn[a[i]]=min(mn[a[i]],dis);
		++cnt[a[i]];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=n;j++)
			if(cnt[j])ans=max(ans,dist(i,j)+n*(cnt[j]-1)+mn[j]);
		cout<<ans<<' ';
	}
}