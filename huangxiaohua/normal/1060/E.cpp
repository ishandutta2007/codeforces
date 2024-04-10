#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,x,y;
ll res,res2,a[200500],f[200500][2],f2[200500][2];
vector<int> v[200500];

void dfs(int x,int fa){
	a[x]++;
	for(auto i:v[x]){
		if(i!=fa){dfs(i,x);a[x]+=a[i];}
	}
	res+=a[x]*(n-a[x]);
}

void dfs2(int x,int fa){
	for(auto i:v[x]){
		if(i!=fa){
			dfs2(i,x);
			f[x][0]+=f[i][1];
			f[x][1]+=f[i][0];
			f[x][1]++;
		}
	}
}

void dfs3(int x,int fa){
	if(!fa){f2[x][0]=f[x][0];f2[x][1]=f[x][1];goto aaa;}
	ll t0,t1;
	t1=f2[fa][1]-1-f[x][0];
	t0=f2[fa][0]-f[x][1];
	f2[x][0]=f[x][0]+t1;
	f2[x][1]=f[x][1]+t0+1;
	aaa:;
	res2+=f2[x][1];
	for(auto i:v[x]){
		if(i!=fa){
			dfs3(i,x);
		}
	}
	//printf("%d %d %d %d %d\n",x,f2[x][0],f2[x][1],f[x][0],f[x][1]);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	dfs3(1,0);
	//printf("%d %d\n",res,res2);
	res2/=2;
	printf("%lld\n",(res+1)/2+res2/2);
}