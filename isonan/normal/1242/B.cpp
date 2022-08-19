#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int>vec[100001],bel[100001];
std::set<int>root,tem;
int n,m,head[100001],nxt[200001],b[200001],k,f[100001],stk[100001],top;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
bool check(int x){
	for(int i=0;i<bel[x].size();i++)if(!tem.count(bel[x][i]))return 0;
	return 1;
}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		vec[b].push_back(a),
		vec[a].push_back(b);
	}
	for(int i=1;i<=n;i++)root.insert(i),bel[i].push_back(i);
	for(int i=1;i<=n;i++){
		tem.clear();
		for(int j=0;j<vec[i].size();j++)tem.insert(vec[i][j]);
		int now=0,fv=find(i);
		top=0;
		for(auto it=root.begin();it!=root.end();++it)stk[++top]=*it;
		for(int k=1;k<=top;k++){
			if(stk[k]==fv)continue;
			if(check(stk[k]))continue;
			int a=fv,b=stk[k];
			if(bel[a].size()>bel[b].size())std::swap(a,b);
			for(int j=0;j<bel[a].size();j++)bel[b].push_back(bel[a][j]);
			f[a]=b;
			root.erase(fv);
			root.erase(stk[k]);
			root.insert(b);
			fv=find(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=!f[i];
	printf("%d\n",cnt-1);
}