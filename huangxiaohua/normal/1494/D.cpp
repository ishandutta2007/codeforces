#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,a[505][505],b[5050],fa[5050],tmp,mx;
int find(int x){
	if(fa[x]==x){return x;}
	return fa[x]=find(fa[x]);
}
vector<int> v[5050];
unordered_set<int> s;
int main(){
	for(i=1;i<=5000;i++){
		fa[i]=i;
	}
	scanf("%d",&n);
	m=n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			mx=max(mx,a[i][j]);
		}
		b[i]=a[i][i];
	}
	while(b[m]!=mx){
		tmp=6666;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				find(i);find(j);
				if(fa[i]==fa[j]){continue;}
				tmp=min(a[i][j],tmp);
			}
		}
		for(i=1;i<=n;i++){
			s.clear();
			s.insert(fa[i]);
			for(j=i+1;j<=n;j++){
				find(i);find(j);
				if(fa[i]==fa[j]){continue;}
				if(a[i][j]==tmp){
					s.insert(fa[j]);
				}
			}
			if(s.size()==1){continue;}
			b[++m]=tmp;
			for(int j:s){
				v[m].push_back(fa[j]);
				fa[j]=m;
			}
		}
	}
	printf("%d\n",m);
	for(i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	printf("\n%d\n",m);
	for(i=1;i<=5000;i++){
		for(auto j:v[i]){
			printf("%d %d\n",j,i);
		}
	}
}