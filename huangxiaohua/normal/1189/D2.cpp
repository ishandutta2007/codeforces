#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int i,j,k,n,m,t,s1[1050],s2[1050],it1,it2,a[1050],w;
vector<pair<int,int> >v[1050];
vector<tuple<int,int,int> >res;

void dfs1(int x,int fa){
	if(a[x]==1){
		s1[it1]=x;return;
	}
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		dfs1(i,x);
	}
}
 
void dfs2(int x,int fa){
	if(a[x]==1){
		s2[it2]=x;return;
	}
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		dfs2(i,x);
	}
}

void dfs(int x,int fa){
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		it1=it2=0;
		
		if(a[x]==1){
			s1[++it1]=x;
		}
		else{
			for(auto [i1,j1]:v[x]){
				if(i1==i)continue;
				it1++;dfs1(i1,x);
			}
		}
		
		if(a[i]==1){
			s2[++it2]=i;
		}
		else{
			for(auto [i1,j1]:v[i]){
				if(i1==x)continue;
				it2++;dfs2(i1,i);
			}
		}
		
		//printf("a%d %d %d %d\n",x,i,it1,it2);
		if(it1==1&&it2==1){
			res.push_back({s1[1],s2[1],j});
		}
		if(it1==1&&it2!=1){
			res.push_back({s1[1],s2[1],j/2});
			res.push_back({s1[1],s2[2],j/2});
			res.push_back({s2[1],s2[2],-j/2});
		}
		if(it1!=1&&it2==1){
			res.push_back({s2[1],s1[1],j/2});
			res.push_back({s2[1],s1[2],j/2});
			res.push_back({s1[1],s1[2],-j/2});
		}
		if(it1!=1&&it2!=1){
			res.push_back({s1[1],s2[1],j/2});
			res.push_back({s1[2],s2[2],j/2});
			res.push_back({s2[1],s2[2],-j/2});
			res.push_back({s1[1],s1[2],-j/2});
		}
		
		dfs(i,x);
	}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&j,&k,&w);
		a[j]++;a[k]++;
		v[j].push_back({k,w});
		v[k].push_back({j,w});
	}
	for(i=1;i<=n;i++){
		if(a[i]==2){
			puts("NO");return 0;
		}
	}
	dfs(1,0);
	puts("YES");
	cout<<res.size()<<endl;
	for(auto [x,y,z]:res){
		printf("%d %d %d\n",x,y,z);
	}
}