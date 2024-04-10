#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
int x[M],p[M],c[M];
vector<int>g[M];
ll h[M];
multiset<int>s;
int ans[M];
void work(){
	s.clear();
	cin>>n>>m;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<=n;++i){
		cin>>x[i]>>p[i];
		c[i]=x[i];
	}
	sort(c+1,c+n+1);
	int num=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;++i){
		int y=lower_bound(c+1,c+num+1,x[i])-c;
		g[y].eb(i);
	}
	ll sum=0;
	for(int i=1;i<=num;++i){
		for(auto o:g[i]){
			sum+=p[o]+c[i];
			s.insert(p[o]+c[i]);
		}
		while(s.size()&&(*s.begin())<=c[i]){
			auto it=s.begin();

			sum-=*it;
			s.erase(s.begin());
		}
		int t=s.size();
		h[i]=sum-1ll*t*c[i];
	}
	sum=0;
	s.clear();
	for(int i=num;i>=1;--i){
		while(s.size()){
			auto it=s.end();
			it--;
			if((*it)>c[i])sum+=(*it),s.erase(it);
			else break;
		}
		int t=s.size();
		h[i]+=sum+1ll*t*c[i];
		for(auto o:g[i]){
			sum+=p[o]-c[i];
			s.insert(c[i]-p[o]);
		}
	}
	int l=num+1,r=0;
	for(int i=1;i<=num;++i){
		if(h[i]>m){
			l=min(l,i);
			r=max(r,i);
		}
	}
	if(r==0){
		for(int i=1;i<=n;++i)putchar('1');
		puts("");
		return;
	}
	ll rex=-(1ll<<60);
	for(int i=1;i<=n;++i)ans[i]=1;
	for(int i=1;i<=num;++i){
		if(h[i]>m)rex=max(rex,h[i]-m-c[i]);
		for(auto o:g[i]){
			if(c[i]-p[o]>c[l]||c[i]+p[o]<c[r]){
				ans[o]=0;
				continue;
			}
			if(p[o]-c[i]<rex)ans[o]=0;
		}
	}
	rex=-(1ll<<60);
	for(int i=num;i>=1;--i){
		if(h[i]>m)rex=max(rex,h[i]-m+c[i]);
		for(auto o:g[i]){
			if(p[o]+c[i]<rex)ans[o]=0;
		}
	}
	for(int i=1;i<=n;++i)putchar('0'+ans[i]);
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*1
2 10
1 10
2 11
*/