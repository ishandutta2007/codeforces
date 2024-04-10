#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
const int B=350;
int n,m;
int a[M],p[M];
pii v[M];
ll val[M];
set<int>s[M];
int id(int i){
	return (i-1)/B+1;
}
int L(int i){
	return (i-1)*B+1;
}
int R(int i){
	return min(i*B,n);
}
void change(int x){
	for(int i=L(x);i<=R(x);++i){
		v[i]=make_pair(p[i],i-p[i]);
	}
	sort(v+L(x),v+R(x)+1);
	val[L(x)]=v[L(x)].se;
	for(int i=L(x);i<R(x);++i){
		val[i+1]=v[i+1].se+val[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)s[i].insert(0),s[i].insert(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[a[i]].insert(i);
	}
	for(int i=1;i<=n;++i){
		p[i]=*prev(s[a[i]].lower_bound(i));
	}
	for(int i=1;i<=id(n);++i)change(i);
	for(int t=1;t<=m;++t){
		int o,l,r;
		cin>>o>>l>>r;
		if(o==1){
			int x=*prev(s[a[l]].lower_bound(l));
			int y=*next(s[a[l]].lower_bound(l));
			p[y]=x;
			change(id(y));
			s[a[l]].erase(l);
			a[l]=r;
			s[a[l]].insert(l);
			x=*prev(s[a[l]].lower_bound(l));
			y=*next(s[a[l]].lower_bound(l));
			p[y]=l;
			p[l]=x;
			change(id(l));
			change(id(y));
		}
		else{
			ll ans=0;
			for(int i=r+1;i<=R(id(r));++i){
				if(p[i]>=l)ans-=i-p[i];
			}
			for(int i=id(l);i<=id(r);++i){
				int x=lower_bound(v+L(i),v+R(i)+1,make_pair(l,0))-v-1;
				ans+=val[R(i)];
				if(x>=L(i))ans-=val[x];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
7 2
1 2 3 1 3 2 2
1 3 2
2 1 6
*/