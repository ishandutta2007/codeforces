#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,siz[200500],siz2[200500],fa[200500],fa2[200500];
int find(int *f,int x){return (f[x]==x)?x:f[x]=find(f,f[x]);}
void add(int *f,int *s,int x,int y){if(x!=y){s[f[x]]+=s[f[y]];f[f[y]]=f[x];}}
ll res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){siz[i]=siz2[i]=1;fa[i]=fa2[i]=i;}
	for(i=1;i<n;i++){
		scanf("%d%d%d",&j,&k,&m);
		if(!m){add(fa,siz,find(fa,j),find(fa,k));}
		else{add(fa2,siz2,find(fa2,j),find(fa2,k));}
	}
	for(i=1;i<=n;i++){
		res+=1ll*siz2[find(fa2,i)]*siz[find(fa,i)]-1;
	}
	cout<<res;
}