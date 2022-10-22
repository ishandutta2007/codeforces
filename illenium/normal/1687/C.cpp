#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int f[N],a[N],b[N],n,m,l[N],r[N];
vector<int> p[N];
ll sa[N],sb[N];
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
inline bool chk(int x){
	return x!=getf(x);
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sa[i]=sa[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		sb[i]=sb[i-1]+b[i];
	}
	for(int i=0;i<=n+1;++i)f[i]=i,p[i].clear();
	queue<int> q;
	int cnt=0;
	for(int i=0;i<=n;++i){
		if(sa[i]==sb[i]){
			q.push(i);
			f[i]=i+1;
			++cnt;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>l[i]>>r[i];
		p[l[i]-1].push_back(i);
		p[r[i]].push_back(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto z:p[u]){
			if(chk(l[z]-1)&&chk(r[z])){
				for(int i=getf(l[z]);i<=r[z];i=getf(i)){
					f[i]=getf(i+1);
					++cnt;
					q.push(i);
				}
			}
		}
	}
	cout<<(cnt==n+1?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}