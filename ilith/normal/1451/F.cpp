#include<bits/stdc++.h>
using namespace std;
int a[110][110],xors[1010];
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(xors,0,sizeof(xors));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				xors[i+j]^=a[i][j];
			}
		}
		bool flag=1;
		for(int i=1;flag&&i<=n+m;++i){
			if(xors[i])flag=0;
		}
		puts(flag?"Jeel":"Ashish");
	}
	return 0;
}