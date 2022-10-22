#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=4e5+9;
int n;
int dp[M<<1];
int a[M],cnt[M],ma;
vector<int>v[M],p,t,pp;
set<int>s;
void add(int x){
	p.eb(x);
	t.eb(x);
	pp.eb(x);
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		v[a[i]].eb(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;++i){
		if(cnt[i]>cnt[ma])ma=i;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==ma)s.insert(i);
	}
	s.insert(0);
	s.insert(n+1);
	for(int i=0;i<=n*4;++i)dp[i]=1e9;
	for(int x=1;x<=n;++x){
		if(x==ma)continue;
		p.clear();
		t.clear();
		for(auto o:v[x]){
			p.eb(o);
			if(s.size()==0)continue;
			auto it=s.upper_bound(o);
			pp.clear();
			auto ne=it,pr=it;
			for(int k=0;k<2;++k){
				if(ne!=s.end()){
					add(*ne);
					ne=next(ne);
				}
				if(pr!=s.begin()){
					add(*prev(pr));
					pr=prev(pr);
				}
			}
			for(auto y:pp)s.erase(y);
		}
		sort(p.begin(),p.end());
		int rex=2*n;
		int last=-1;
		for(auto o:p){
			if(dp[rex]!=last)ans=max(ans,o-dp[rex]-1);
			if(a[o]==x)rex++;
			else rex--;
			if(dp[rex]==1e9)dp[rex]=o;
			last=o;
		}
		rex=2*n;
		for(auto o:p){
			if(a[o]==x)rex++;
			else rex--;
			dp[rex]=1e9;
		}
		for(auto o:t)s.insert(o);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
12
2 1 2 1 1 1 1 1 1 1 2 1
*/