#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[1005],f[505][505][2],res;

int fuck(int id,int x,int y){
	if(id>n)return 0;
	if(~f[id][x][y])return f[id][x][y];
	int &t=f[id][x][y],i;
	for(i=id;i<=n;i++)t=max(t,fuck(i+1,x+1,1)+a[id]*(i-id+1)*y);
	for(i=1;i<=x;i++)t=max({t,fuck(i+id,x-i+1,0)+i*a[id+i],fuck(i+id,x-i,1)+i*a[id+i]});
	return t;
}

int main(){
	memset(f,-1,sizeof(f));
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cout<<fuck(1,1,1);
}