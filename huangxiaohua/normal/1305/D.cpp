#pragma GCC optimize(2)
#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
int n,a,b,c,i,res,used[1050],son[1050];
 
vector<int> v[1050];
queue<int> q;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n-1;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		son[a]++;son[b]++;
	}
	for(i=1;i<=n;i++){
		if(son[i]==1){q.push(i);}
	}
	while(1){
		a=q.front();q.pop();
		if(q.empty()){printf("! %d",a);return 0;}
		b=q.front();q.pop();
		used[a]=used[b]=1;
		printf("? %d %d\n",a,b);
		fflush(stdout);
		scanf("%d",&res);
		if(res==a||res==b){printf("! %d",res);return 0;}
		
		for(i=0;i<v[a].size();i++){
			c=v[a][i];
			if(!used[c]){son[c]--;if(son[c]==1){q.push(c);}}
		}
		
		for(i=0;i<v[b].size();i++){
			c=v[b][i];
			if(!used[c]){son[c]--;if(son[c]==1){q.push(c);}}
		}
	}
}