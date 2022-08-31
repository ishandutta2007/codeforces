#include<bits/stdc++.h>
const int MAXN=100;
int n,k,x0,y0;
bool a[MAXN+5][MAXN+5];
int calc(int x,int y1,int y2){
	int ans=(y2-y1+1)*abs(x-x0);
	if(y1>=y0)
		ans-=(y1-y0)*(y1-y0-1)/2;
	else
		ans+=(y0-y1)*(y0-y1+1)/2;
	if(y2<=y0)
		ans-=(y0-y2)*(y0-y2-1)/2;
	else
		ans+=(y2-y0)*(y2-y0+1)/2;
	return ans;
}
void solve(int n){
	int x=0,y=0,ans=1e9;
	for(int i=1;i<=k;++i){
		int sum=0;
		for(int j=1;j<=n-1;++j)
			sum+=a[i][j];
		for(int j=1;j<=k-n+1;++j){
			sum=sum+a[i][j+n-1]-a[i][j-1];
			if(!sum){
				int d=calc(i,j,j+n-1);
				if(d<ans){
					x=i;
					y=j;
					ans=d;
				}
			}
		}
	}
	if(x){
		for(int i=y;i<=y+n-1;++i)
			a[x][i]=1;
		printf("%d %d %d\n",x,y,y+n-1);
	}else
		puts("-1");
}
int main(){
	scanf("%d%d",&n,&k);
	x0=(k+1)/2;
	y0=(k+1)/2;
	for(int i=1;i<=n;++i){
		int m;
		scanf("%d",&m);
		solve(m);
	}
	return 0;
}