#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,m1,x[4000500],y[4000500],vis[400500],mark[400500],st[400500],res[400500],ans;
string s1[400500];
set<int> s[400500];
vector<vector<int> >mp;
vector<int> lv[400500],rv[400500];

void add(int a,int b){
	x[++m1]=a;y[m1]=b;
	lv[a].push_back(b);
	rv[b].push_back(a);
}

void dfs1(int x){
	vis[x]=1;
	for(auto i:lv[x]){
		if(!vis[i])dfs1(i);
	}
	st[++t]=x;
}

void dfs2(int x){
	mark[x]=t;
	for(auto i:rv[x]){
		if(!mark[i])dfs2(i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	vector<int> v1(n+2,0);
	for(i=0;i<=m+1;i++){
		s[i].insert(-1);s[i].insert(1145141919);
		mp.push_back(v1);
	}
	for(i=1;i<=n;i++){
		cin>>s1[i];s1[i]="X"+s1[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s1[i][j]=='#'){
				mp[j][n-i+1]=++k;
				s[j].insert(n-i+1);
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(mp[i][j]){
				if(mp[i][j+1]){add(mp[i][j],mp[i][j+1]);}
				auto it=s[i].find(j);it--;if(*it>0){add(mp[i][j],mp[i][*it]);}
				it=s[i-1].upper_bound(j);it--;if(*it>0){add(mp[i][j],mp[i-1][*it]);}
				it=s[i+1].upper_bound(j);it--;if(*it>0){add(mp[i][j],mp[i+1][*it]);}
			}
		}
	}
	for(i=1;i<=k;i++)if(!vis[i]){dfs1(i);}t=0;
	for(i=k;i>=1;i--)if(!mark[st[i]]){t++;dfs2(st[i]);}
	for(i=1;i<=m1;i++){if(mark[x[i]]==mark[y[i]]){continue;}res[mark[y[i]]]++;}
	for(i=1;i<=t;i++){if(!res[i]){ans++;}}
	printf("%d",ans);
}