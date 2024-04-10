#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Maxn 60
#define Inf (1<<30)
char g[Maxn+5][Maxn+5];
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",g[i]);
	}
	int ans=Inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='A'){
				int z=2;
				if(i>0&&i+1<n){
					z++;
				}
				if(j>0&&j+1<m){
					z++;
				}
				ans=min(ans,z);
			}
		}
	}
	for(int i=0;i<n;i++){
		int z=0;
		for(int j=0;j<m;j++){
			z+=(g[i][j]=='A');
		}
		if(z==m){
			ans=min(ans,1+(i>0&&i+1<n));
		}
	}
	for(int j=0;j<m;j++){
		int z=0;
		for(int i=0;i<n;i++){
			z+=(g[i][j]=='A');
		}
		if(z==n){
			ans=min(ans,1+(j>0&&j+1<m));
		}
	}
	int z=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			z+=(g[i][j]=='A');
		}
	}
	if(z==n*m){
		ans=0;
	}
	if(ans==Inf){
		puts("MORTAL");
	}
	else{
		printf("%d\n",ans);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}