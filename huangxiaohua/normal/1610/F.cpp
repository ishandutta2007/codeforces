#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,a[300500],f[300500],res,x,y,ans[300500],st[300500],ed[300500],sb1,sb2,it2,st2[300500],ed2[300500];
set<pair<int,int> > v1[300500],v2[300500];
//int vis[300500],ok,vis2[300500];
deque<int> q;

int w[300500],vis[300500];
vector<int> sb[300500];
vector<pair<int,int> >v[300500];

void dfs1(int sb){
	if(v2[sb].empty()){
		return;
	}
	auto [i,j]=*v2[sb].begin();
	v2[sb].erase({i,j});
	v2[i].erase({sb,j});
	sb2=i;
	q.push_back(j);
	dfs1(i);
}

void dfs2(int sb){
	if(v2[sb].empty()){
		return;
	}
	auto [i,j]=*v2[sb].begin();
	v2[sb].erase({i,j});
	v2[i].erase({sb,j});
	sb1=i;
	q.push_front(j);
	dfs2(i);
}

void dfs11(int sb){
	if(v1[sb].empty()){
		return;
	}
	auto [i,j]=*v1[sb].begin();
	v1[sb].erase({i,j});
	v1[i].erase({sb,j});
	sb2=i;
	q.push_back(j);
	dfs11(i);
}

void dfs22(int sb){
	if(v1[sb].empty()){
		return;
	}
	auto [i,j]=*v1[sb].begin();
	v1[sb].erase({i,j});
	v1[i].erase({sb,j});
	sb1=i;
	q.push_front(j);
	dfs22(i);
}

void dfs3(int x){
	for(auto [i,j]:v[x]){
		if(vis[j])continue;
		vis[j]=1;
		int k=0;
		if(f[x]<=0){
			f[x]+=w[j];
			f[i]-=w[j];
			if(st2[j]!=x){
				k^=1;
			}
		}
		else{
			f[x]-=w[j];
			f[i]+=w[j];
			if(ed2[j]!=x){
				k^=1;
			}
		}
		for(auto y:sb[j]){
			if((y<0&&k)||(y>0&&!k)){
				ans[abs(y)]=1;
			}
			else{
				ans[abs(y)]=2;
			}
		}
		dfs3(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>x>>y>>k;
		st[i]=x;
		ed[i]=y;
		if(k==1){
			v1[x].insert({y,i});
			v1[y].insert({x,i});
		}
		else{
			v2[x].insert({y,i});
			v2[y].insert({x,i});
		}
	}
	
	for(i=1;i<=n;i++){
		while(1){
			//cout<<i<<endl;
			
			if(v2[i].empty())break;
			sb1=sb2=i;
			q.clear();
			dfs1(i);
			dfs2(i);
			
			//printf("a%d %d\n",sb1,sb2);
			
			if(sb1!=sb2){
				v[sb1].push_back({sb2,++it2});
				v[sb2].push_back({sb1,it2});
				w[it2]=2;
				st2[it2]=sb1;
				ed2[it2]=sb2;
			}
			
			while(!q.empty()){
				k=q.front();
				//printf("nmsl%d %d %d\n",st[k],ed[k],k);
				
				q.pop_front();
				if(st[k]==sb1){
					sb[it2].push_back(k);
					sb1=ed[k];
					ans[k]=1;
				}
				else{
					sb[it2].push_back(-k);
					ans[k]=2;
					sb1=st[k];
				}
			}
		}
		
		while(1){
			//cout<<i<<endl;
			
			if(v1[i].empty())break;
			sb1=sb2=i;
			q.clear();
			dfs11(i);
			dfs22(i);
			
			//printf("a%d %d\n",sb1,sb2);
			
			if(sb1!=sb2){
				v[sb1].push_back({sb2,++it2});
				v[sb2].push_back({sb1,it2});
				w[it2]=1;
				st2[it2]=sb1;
				ed2[it2]=sb2;
			}
			
			while(!q.empty()){
				k=q.front();
				//printf("nmsl%d %d %d\n",st[k],ed[k],k);
				
				q.pop_front();
				if(st[k]==sb1){
					sb[it2].push_back(k);
					sb1=ed[k];
					ans[k]=1;
				}
				else{
					sb[it2].push_back(-k);
					ans[k]=2;
					sb1=st[k];
				}
			}
		}
	}
	
	/*for(i=1;i<=n;i++){
		for(auto [x,y]:v[i]){
			if(x<i)continue;
			printf("a%d %d %d\n",i,x,w[y]);
			for(auto k:sb[y]){
				printf("%d ",k);
			}
			puts("");
		}
	}*/
	
	for(i=1;i<=n;i++){
		dfs3(i);
	}
	for(i=1;i<=n;i++){
		if(f[i]&1)res++;
	}
	
	cout<<res<<endl;
	for(i=1;i<=m;i++){
		cout<<ans[i];
	}
}