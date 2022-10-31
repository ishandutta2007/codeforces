#include<bits/stdc++.h>
using namespace std;
 
int i,j,k,n,m,d,sb,tmp,a[10500],pre;
 
vector<int> v[10500];
bool cmp(int a,int b){return __builtin_popcount(a)>__builtin_popcount(b);}
 
int mch[10500];
bool vis[10500];
bool dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (auto i : v[u]) if ((mch[i] == 0) || dfs(mch[i])) {mch[i] = u;return 1;}
	return 0;
}
stack<int> s;
 
int main(){
	scanf("%d%d",&d,&n);
	for(i=1;i<=n;i++){
		for(j=0;j<d;j++){
			scanf("%1d",&k);
			a[i]+=(k<<j);
		}
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i!=j&&(a[i]&a[j])==a[i]){
			v[i].push_back(j);}
		}
	}
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		if(vis[i]){continue;}
		s.push(-1);
		k=mch[i];pre=a[i];
		while(k){
			vis[k]=1;
			for(j=0;j<d;j++){
				if((a[k]^pre)&(1<<j)){s.push(j);}
			}
			pre=a[k];
			k=mch[k];
		}
		for(j=0;j<d;j++){if(pre&(1<<j)){s.push(j);}}
	}
	printf("%d\n",s.size()-1);
	while(s.size()>1){
		if(s.top()==-1){printf("R ");}
		else{printf("%d ",s.top());}
		s.pop();
	}
}