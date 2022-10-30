#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500],x,y,vis[200500],a[200500],mn,r1,r2,k1,k2;
vector<int> v[200500],v2[200500];
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v2[y].push_back(x);
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&a[i]);
	}
	q.push(a[t]);vis[a[t]]=1;
	while(!q.empty()){
		x=q.front();q.pop();
		for(auto i:v2[x]){
			if(!vis[i]){
				vis[i]=1;q.push(i);f[i]=f[x]+1;
			}
		}
	}
	/*for(i=1;i<=n;i++){
		printf("a%d %d\n",i,f[i]);
	}*/
	for(i=1;i<t;i++){
		x=a[i];y=a[i+1];k1=k2=0;
		mn=1145141919;
		for(auto j:v[x]){
			mn=min(mn,f[j]);
		}
		for(auto j:v[x]){
			if(f[j]==mn){
				if(j==y){k2++;}
				k1++;
			}
		}
		if(!k2){r1++;r2++;}
		if(k2&&k1>k2){r2++;}
	}
	printf("%d %d",r1,r2);
}