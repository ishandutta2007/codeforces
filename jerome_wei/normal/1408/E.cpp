#include<bits/stdc++.h>
using namespace std;

struct edge{
	int x,y,w;
	edge(int x=0,int y=0,int w=0):x(x),y(y),w(w){}
	bool operator < (const edge b)const{
		return w < b.w;
	}
};

vector<edge> e;
int n,m;
const int N = 4e5+5;
int a[N], b[N];
int par[N];
inline int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		int sz;scanf("%d",&sz);
		for(int j=1;j<=sz;j++){
			int y;scanf("%d",&y);
			e.push_back(edge(i,n+y,a[i]+b[y]));
		}
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	for(int i=1;i<=n+m;i++)par[i] = i;
	long long ans=0;
	for(auto p:e){
		int u=find(p.x),v=find(p.y);
		if(u!=v){
			par[u]=v;
		}else{
			ans+=p.w;
		}
	}
	cout << ans << endl;
}