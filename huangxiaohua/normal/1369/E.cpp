#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[200500],it,a[200500],b[200500],u[200500],x,y;
vector<pair<int,int> >v[200500];
queue<int> q;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back({k,i});
		v[k].push_back({j,i});
		b[j]++;b[k]++;
	}
	for(i=1;i<=n;i++){
		if(a[i]>=b[i]){q.push(i);u[i]=1;}
	}
	while(!q.empty()){
		x=q.front();q.pop();
		for(auto [i,j]:v[x]){
			if(u[i]==2){continue;}
			res[++it]=j;b[i]--;
			if(b[i]<=a[i]&&!u[i]){
				q.push(i);u[i]=1;
			}
		}
		u[x]=2;
	}
	if(it>m){return 1;}
	if(it!=m){puts("DEAD");return 0;}
	puts("ALIVE");
	for(i=it;i>=1;i--){
		printf("%d ",res[i]);
	}
}