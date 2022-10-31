#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

int j,k,t,i,n,x,y;
vector<int> v[200500];
bool used[200500],huan[200500];
ll res,tmp;

bool dfs1(int n,int dad){
	int i,j;
	used[n]=1;
	for(i=0;i<v[n].size();i++){
		if(used[v[n][i]]){
			if(v[n][i]!=dad){
				huan[v[n][i]]=1;
				huan[n]=1;return 1;
			}
			else{continue;}
		}
		if(dfs1(v[n][i],n)){
			if(huan[n]){return 0;}
			huan[n]=1;return 1;
		}
	}
	return 0;
}

void dfs2(int n){
	int i,j;
	used[n]=1;tmp++;
	for(i=0;i<v[n].size();i++){
		if(used[v[n][i]]||huan[v[n][i]]){
			continue;
		}
		dfs2(v[n][i]);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=tmp=0;
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		memset(used,0,sizeof(bool)*n+8);
		memset(huan,0,sizeof(bool)*n+8);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,-1);
		
		memset(used,0,sizeof(bool)*n+10);
		for(i=1;i<=n;i++){
			if(huan[i]){
				tmp=0;
				dfs2(i);
				res+=(n-tmp)*tmp;
				res+=(tmp*tmp-tmp)/2;
			}
		}
		printf("%lld\n",res);
	}
}