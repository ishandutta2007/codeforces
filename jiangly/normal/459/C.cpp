#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k,d,cnt;
int a[N],ans[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
void dfs(int x){
	if(x==d+1){
		++cnt;
		for(int i=1;i<=d;++i){
			ans[i][cnt]=a[i];
		}
	}else{
		for(int i=1;i<=k;++i){
			a[x]=i;
			dfs(x+1);
			if(cnt==n){
				return;
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	if(pow(k,d)<2000&qpow(k,d)<n){
		printf("-1");
	}else{
		dfs(1);
		for(int i=1;i<=d;++i){
			for(int j=1;j<=n;++j){
				printf("%d ",ans[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}