#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666],x,y,vis[666];
int main(){
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		a[1]=x;
		
		k=n;
		for(i=2;i<=(n/2);i++){
			while(k==y|k==x){
				k--;
			}
			if(!k){
				puts("-1");goto aaa;
			}
			a[i]=k;
			vis[k]=1;
			k--;
		}
		k=1;
		for(i=(n/2+1);i<=n;i++){
			while(vis[k]){
				k++;
			}
			a[i]=k;
			vis[k]=1;
		}
		if(k!=y){
			puts("-1");goto aaa;
		}
		for(i=1;i<=(n/2);i++){
			if(a[i]<x){
				puts("-1");goto aaa;
			}
		}
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}puts("");
		aaa:;
	}
}