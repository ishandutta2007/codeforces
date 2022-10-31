#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define b(x) (1<<((x)-1))
//
int i,j,k,n,m,t,fa[300500],x,y;

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
ll res,a[300500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=262143;i++)fa[i]=i;
	a[0]=1;
	for(i=1;i<=n;i++){
		cin>>k;a[k]++;res-=k;
	}
	for(i=262143;i>=1;i--){
		for(j=i;j;j=((j-1)&i)){
			if(j<(i^j))break;
			x=find(j);y=find(i^j);
			if(x==y||!a[x]||!a[y])continue;
			res+=(a[x]+a[y]-1)*i;
			a[x]=a[y]=1;
			fa[x]=fa[y];
		}
	}
	cout<<res;
}