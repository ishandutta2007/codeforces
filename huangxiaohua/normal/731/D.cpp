#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,t,m,it,res[1005000];
vector<int> v[500500];

void chk(int x,int y){
	if(!v[x][y]){return;}
	if(!v[x+1][y]){puts("-1");exit(0);}
	if(v[x][y]==v[x+1][y]){chk(x,y+1);return;}
	if(v[x][y]<v[x+1][y]){res[m-v[x+1][y]+1]=max(m-v[x][y],res[m-v[x+1][y]+1]);}
	else{res[0]=max(m-v[x][y],res[0]);res[m-v[x+1][y]+1]=m;}
}

int main(){
	memset(res,-1,sizeof(res));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(j=1;j<=k;j++){scanf("%d",&it);v[i].push_back(it);}
		v[i].push_back(0);
	}
	for(i=1;i<n;i++){chk(i,0);}k=-1;
	for(i=0;i<m;i++){if(k<i&&res[i]==-1){printf("%d",i);return 0;}k=max(k,res[i]);}
	puts("-1");
}