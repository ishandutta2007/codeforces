#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e3+9;
int n,k;
int a[M][M],b[M][M],vis[M][M];
void work(){
	scanf("%d%d",&n,&k);
	k=n-k+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%1d",&a[i][j]);
			vis[i][j]=0;
			b[i][j]=1;
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=k;++j){
			vis[i][j]=max(vis[i-1][j],vis[i][j-1]);
			while(a[i+vis[i][j]][j+vis[i][j]]==0&&vis[i][j]+max(i,j)<=n)vis[i][j]++;
			if(vis[i][j]+max(i,j)>n){
				puts("NO");
				return;
			}
			b[i+vis[i][j]][j+vis[i][j]]=0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)putchar(b[i][j]+'0');
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}