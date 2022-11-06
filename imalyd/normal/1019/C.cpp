#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,t[N],f[N],x[N],y;
vector<int>e[N];
int rd(){
	int a=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
	return a;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
	}
	for(int i=1;i<=n;i++)if(!t[i]){
		t[i]=i;
		for(int j=0;j<(int)e[i].size();j++)if(!t[e[i][j]])t[e[i][j]]=i;
	}
	for(int i=n;i;i--)if(t[i]==i&&!f[i]){
		x[++y]=i;
		for(int j=0;j<(int)e[i].size();j++)f[e[i][j]]=1;
	}
	printf("%d\n",y);
	while(y)printf("%d ",x[y--]);
	return 0;
}