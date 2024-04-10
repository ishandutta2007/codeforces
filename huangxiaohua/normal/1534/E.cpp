#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,vis[505],sb,a[505],fa[505],num[505],res;

queue<int> q;
vector<int> v,qu;
int main(){
	scanf("%d%d",&n,&m);
	q.push(0);
	vis[0]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		int mn=min(x,m);
		for(i=0;i<=mn;i++){
			if(x+m-i>n){continue;}
			sb=x+m-2*i;
			if(!vis[sb]){
				vis[sb]=vis[x]+1;
				fa[sb]=x;num[sb]=i;
				q.push(sb);
			}
		}
	}
	if(!vis[n]){puts("-1");return 0;}
	sb=n;
	while(sb){
		v.push_back(num[sb]);
		sb=fa[sb];
	}
	reverse(v.begin(),v.end());
	for(auto i:v){
		qu.clear();
		sb=1;
		for(j=1;sb<=i;j++){
			if(a[j]){qu.push_back(j);sb++;}
		}
		sb=1;
		for(j=1;sb<=m-i;j++){
			if(!a[j]){qu.push_back(j);sb++;}
		}
		printf("? ");
		for(auto j:qu){
			a[j]^=1;
			printf("%d ",j);
		}puts("");
		fflush(stdout);
		sb=0;
		scanf("%d",&sb);
		res^=sb;
	}
	printf("! %d",res);fflush(stdout);
}