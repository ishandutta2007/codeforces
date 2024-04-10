#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map< int ,unordered_map<int,int> >mp;

struct node{
	int x,y,l;
	bool operator <(const node a)const{
		return l>a.l;
	}
}b[200500],tmp,tmp2;

int i,j,k,n,t,m,x,y,l,mx,n2,used[200500],col[200500],fa[200500],fx,fy;
vector<int> v[200500];
ll res;

priority_queue<node> q,q2;

void dfs(int n){
	//printf("d%d %d\n",t,n);
	used[n]=1;
	col[n]=n2;
	int i;
	for(i=0;i<v[n].size();i++){
		if(used[v[n][i]]){continue;}
		dfs(v[n][i]);
	}
}

int find(int k){
	if(!fa[k]){return 0;}
	if(fa[k]==k){return k;}
	return fa[k]=find(fa[k]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		while(!q.empty()){
			q.pop();
		}
		
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&l);
			b[i].x=x;b[i].y=y;b[i].l=l;
			q.push(b[i]);
		}
		
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		
		mx=0;
		while(!q.empty()&&q.top().l<=k){
			mx=max(q.top().l,mx);
			v[q.top().x].push_back(q.top().y);
			v[q.top().y].push_back(q.top().x);
			q.pop();
		}
		mp.clear();
		memset(used,0,n*4+50);
		n2=0;
		
		for(i=1;i<=n;i++){
			if(used[i]){continue;}
			n2++;
			dfs(i);
		}
		
		if(n2==1){
			res=k-mx;
			if(!q.empty()){res=min(res,(ll)q.top().l-k);}
			printf("%lld\n",res);continue;
		}
		
		while(!q2.empty()){
			q2.pop();
		}
		
		while(!q.empty()){
			tmp=q.top();q.pop();
			if(col[tmp.x]==col[tmp.y]){continue;}
			tmp2.x=col[tmp.x];tmp2.y=col[tmp.y];tmp2.l=tmp.l;
			q2.push(tmp2);
		}
		
		res=0;
		memset(used,0,n2*4+50);
		memset(fa,0,n2*4+50);
		while(!q2.empty()){
			tmp=q2.top();q2.pop();
			fx=find(tmp.x);fy=find(tmp.y);
			if(fx&&fx==fy){continue;}
			res+=tmp.l-k;
			if(!fx&&!fy){
				fa[tmp.x]=fa[tmp.y]=tmp.x;continue;
			}
			if(fx&&!fy){
				fa[tmp.y]=fa[tmp.x];continue;
			}
			if(!fx&&fy){
				fa[tmp.x]=fa[tmp.y];continue;
			}
			fa[fa[tmp.x]]=fa[tmp.y];
		}
		printf("%lld\n",res);
	}
}