#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,x,y;
int f[105][105][2][2];

int dfs(int x,int y,int cur,int su){
	if(~f[x][y][cur][su]){
		return f[x][y][cur][su];
	}
	if(!x&&!y){
		if(cur){
			return (!su);
		}
		else{
			return su;
		}
	}
	
	int res=0;
	
	if(cur==1){
		if(x){
			if(!dfs(x-1,y,cur^1,su^1))res=1;
		}
		if(y){
			if(!dfs(x,y-1,cur^1,su))res=1;
		}
	}
	else{
		if(x){
			if(!dfs(x-1,y,cur^1,su))res=1;
		}
		if(y){
			if(!dfs(x,y-1,cur^1,su))res=1;
		}
	}
	
	return f[x][y][cur][su]=res;
}

int main(){
	memset(f,-1,sizeof(f));
	
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		x=y=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>k;
			if(k&1)x++;
			else y++;
		}
		int res=dfs(x,y,1,0);
		if(res)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}