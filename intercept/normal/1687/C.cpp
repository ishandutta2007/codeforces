#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
int a[M],b[M];
vector<int>L[M];
ll p[M];
set<int>s;
int x[M],y[M],d[M];
void work(){
	s.clear();
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i)L[i].clear();
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i){
		p[i]=p[i-1]+a[i]-b[i];
		if(p[i]!=0)s.insert(i);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--;
		d[i]=(p[x[i]]!=0)+(p[y[i]]!=0);
		if(p[x[i]])L[x[i]].eb(i);
		if(p[y[i]])L[y[i]].eb(i);
	}
	queue<int>q;
	for(int i=1;i<=m;++i){
		if(d[i]==0)q.push(i);
	}
	while(!q.empty()){
		int i=q.front();
		q.pop();
		while(1){
			auto it=s.lower_bound(x[i]);
			auto o=*it;
			if(it==s.end()||o>y[i])break;
			for(auto x:L[o]){
				d[x]--;
				if(d[x]==0)q.push(x);
			}
			s.erase(it);
		}
	}
	if(s.size()>0)puts("NO");
	else puts("YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*

1
5 2
1 5 4 2 3
3 2 4 5 1
1 2
2 4

*/