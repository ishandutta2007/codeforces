#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050][1050],fa[2050],lst[2050],x,y,z,sb;

int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n+n;i++)fa[i]=i;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(a[i][j]==a[j][i])continue;
				if(a[i][j]>a[j][i]){
					x=find(i);y=find(j+n);z=find(j);sb=find(i+n);
					if(x==z){
						continue;
					}
					swap(a[i][j],a[j][i]);
					fa[x]=y;
					fa[z]=sb;
					
				}
				else{
					x=find(i);y=find(j+n);z=find(j);sb=find(i+n);
					if(x==y){
						swap(a[i][j],a[j][i]);
						continue;
					}
					fa[x]=z;
					fa[y]=sb;
				} 
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)cout<<a[i][j]<<' ';
			cout<<'\n';
		}
	}
}