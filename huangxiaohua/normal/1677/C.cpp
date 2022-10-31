#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],b[100500],p[100500],vis[100500],NMSL,x,y;
ll res;
vector<int> v;

bool cmp(int x,int y){
	if((x&1)!=(y&1))return (x&1)<(y&1);
	return y<x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		x=1;y=n;
		for(i=1;i<=n;i++){
			p[a[i]]=b[i];
			vis[i]=0;
		}
		res=0;k=0;
		NMSL=0;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			j=i;k=0;
			while(!vis[j]){
				vis[j]=1;
				j=p[j];
				k++;
			}
			if(k&1)NMSL++;
		}
		while((y-x-1)>=NMSL){
			res+=(y-x)*2;y--;x++;
		}
		cout<<res<<'\n';
	}
}