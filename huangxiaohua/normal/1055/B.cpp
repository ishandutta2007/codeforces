#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],l,fa[100500],res,ty;
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main() {
	for(i=1;i<=100000;i++)fa[i]=i;
	ios::sync_with_stdio(0);
	cin>>n>>m>>l;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		if(a[i]>l)res++;
		if(a[i]>l&&a[i-1]>l&&find(i)!=find(i-1)){
			fa[find(i)]=fa[find(i-1)];
			res--;
		}
		if(a[i]>l&&a[i+1]>l&&find(i)!=find(i+1)){
			fa[find(i)]=fa[find(i+1)];
			res--;
		}
	}
	while(m--){
		cin>>ty;
		if(ty==0){
			cout<<res<<'\n';
		}
		else{
			cin>>i>>j;
			if(a[i]>l)continue;
			a[i]+=j;
			if(a[i]>l){
				res++;
				if(a[i]>l&&a[i-1]>l&&find(i)!=find(i-1)){
					fa[find(i)]=fa[find(i-1)];
					res--;
				}
				if(a[i]>l&&a[i+1]>l&&find(i)!=find(i+1)){
					fa[find(i)]=fa[find(i+1)];
					res--;
				}
			}
		}
	}
}