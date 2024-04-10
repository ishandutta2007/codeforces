#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,m;
map<int,char>mp[M];
int bol[2];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		char z[5],c[5];
		scanf("%s",z);
		if(z[0]=='+'){
			scanf("%d%d%s",&x,&y,c);
			mp[x][y]=c[0];
			if(mp[y].count(x)){
				bol[1]++;
				if(mp[y][x]==c[0])bol[0]++;
			}
			
		}
		if(z[0]=='-'){
			scanf("%d%d",&x,&y);
			if(mp[y].count(x)){
				bol[1]--;
				if(mp[y][x]==mp[x][y])bol[0]--;
			}
			mp[x].erase(y);
		}
		if(z[0]=='?'){
			scanf("%d",&x);
			if(x&1)printf(bol[1]?"YES\n":"NO\n");
			else printf(bol[0]?"YES\n":"NO\n");
		}
	}
	return 0;
}