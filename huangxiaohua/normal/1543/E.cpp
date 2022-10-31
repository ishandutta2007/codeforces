#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,nn,x,y,vis[66666],it,res[66666];

vector<int> v[66666];
struct sb{
	int x,y;
	bool operator<(const sb a)const{return x<a.x;}
}s[66666];

//
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		nn=(1<<n);
		m=nn/2*n;
		for(i=0;i<nn;i++){
			v[i].clear();
			s[i].x=0;
			s[i].y=i;
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		memset(vis,0,sizeof(vis));
		it=1;
		queue<int> q,q2;
		for(auto i:v[0]){
			s[i].x=it;it*=2;
		}
		q.push(0);vis[0]=2;
		it=0;
		while(!q.empty()){
			it++;
			while(!q.empty()){
				x=q.front();q.pop();
				vis[x]=2;
				for(auto i:v[x]){
					if(vis[i]==2){continue;}
					s[i].x|=s[x].x;
					if(!vis[i]){q2.push(i);vis[i]=1;}
				}
			}
			swap(q,q2);
		}
		sort(s,s+nn);
		for(i=0;i<nn;i++){
			printf("%d ",s[i].y);
		}puts("");
		if(n!=1&&n!=2&&n!=4&&n!=8&&n!=16){puts("-1");continue;}
		it=0;
		for(i=0;i<nn;i++){
			it=0;
			for(j=0;j<n;j++){
				if(i&(1<<j)){it^=j;}
			}
			res[s[i].y]=it;
		}
		for(i=0;i<nn;i++){
			printf("%d ",res[i]);
		}
		puts("");
	}
}