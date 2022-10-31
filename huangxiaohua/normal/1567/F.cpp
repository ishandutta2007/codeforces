#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,res[505][505],sb;
vector<pair<int,int> > v={{0,1},{0,-1},{1,0},{-1,0}};
char s[505][505];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){cin>>s[i]+1;}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			k=0;
			for(auto [x,y]:v){k+=(s[x+i][y+j]=='.');}
			if(s[i][j]=='X'){
				sb^=(s[i-1][j]=='X');
				if(k&1){cout<<"NO";return 0;}
			}
			else{
				res[i][j]=((j+sb)&1)?1:4;
			}
		}
	}
	puts("YES");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s[i][j]=='X'){
				for(auto [x,y]:v){
					if(s[x+i][y+j]=='.'){res[i][j]+=res[x+i][y+j];}
				}
			}
			printf("%d ",res[i][j]);
		}puts("");
	}
}