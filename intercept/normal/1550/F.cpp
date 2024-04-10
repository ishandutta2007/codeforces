#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,q,S,d;
int a[M],dis[M],b[1000006],T[M<<1];
set<int>s,t;
void push(int x,int y){
	for(T[x+=n-1]=y;x;x>>=1)T[x>>1]=dis[T[x]]<dis[T[x^1]]?T[x]:T[x^1];
}
void get(int u){
	for(int v:{a[u]-d,a[u]+d}){
		auto it=t.lower_bound(v);
		if(it!=t.end()){
			v=b[*it];
			dis[u]=min(dis[u],max(dis[v],abs(d-abs(a[u]-a[v]))));
			push(u,u);
		}
		if(it!=t.begin()){
			it--;
			v=b[*it];
			dis[u]=min(dis[u],max(dis[v],abs(d-abs(a[u]-a[v]))));
			push(u,u);
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&q,&S,&d);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s.insert(a[i]);
		b[a[i]]=i;
	}
	for(int i=0;i<=n;++i)dis[i]=1e6;
	dis[S]=0;
	push(S,S);
	for(int i=1;i<=n;++i){
		int u=T[1];
		push(u,0);
		s.erase(a[u]);
		t.insert(a[u]);
		for(int v:{a[u]-d,a[u]+d}){
			auto it=s.lower_bound(v);
			if(it!=s.end()){
				v=b[*it];
				dis[v]=min(dis[v],max(dis[u],abs(d-abs(a[u]-a[v]))));
				push(v,v);
			}
			if(it!=s.begin()){
				it--;
				v=b[*it];
				dis[v]=min(dis[v],max(dis[u],abs(d-abs(a[u]-a[v]))));
				push(v,v);
			}
		}
		auto it=s.lower_bound(a[u]);
		if(it!=s.end())get(b[*it]);
		if(it!=s.begin()){it--;get(b[*it]);}
	}
	for(int i=1,x,k;i<=q;++i){
		scanf("%d%d",&x,&k);
		puts(dis[x]<=k?"YES":"NO");
	}
	return 0;
}