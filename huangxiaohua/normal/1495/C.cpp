#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[600][600];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		for(i=1;i<=500;i++){
			s[n+1][i]='.';
		}
		for(i=1;i<=n;i+=3){
			for(j=1;j<=m;j++){
				s[i][j]='X';
			}
		}
		for(i=2;i<=n;i+=3){
			for(j=1;j<=m;j++){
				if(s[i][j]=='X'){
					s[i+1][j]='X';goto aaa;
				}
				if(s[i+1][j]=='X'){
					s[i][j]='X';goto aaa;
				}
			}
			s[i][1]=s[i+1][1]='X';
			aaa:;
		}
		if((n%3)==0){
			for(i=1;i<=m;i++){
				if(s[n][i]=='X'){s[n-1][i]='X';}
				if(s[n-1][i]=='X'){s[n][i]='X';}
			}
		}
		for(i=1;i<=n;i++){
			cout<<s[i]+1<<endl;
		}
	}
}