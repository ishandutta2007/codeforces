#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;
vector<int>a;

unordered_map<char,int>mp={{'A',0},{'N',1},{'O',2},{'T',3}};
unordered_map<int,char>pm={{0,'A'},{1,'N'},{2,'O'},{3,'T'}};

template<class T>
struct fenwick{
	T n;vector<T>a;
	fenwick(int n_):n(n_+1),a(n){}; 
	T query(int i){
		++i;
		T r=0;
		for(;i;i-=i&-i)r+=a[i];
		return r;
	}
	void update(int i,T d){
		++i;
		for(;i<n;i+=i&-i)a[i]+=d;
	}
};


ll opers(vector<int>b){
	int nxt[4]={n,n,n,n};
	for(int i=0;i<4;++i)
		for(int j=n-1;j>=0;--j)
			if(b[j]==i)
				nxt[i]=j;
	ll res=0;
	fenwick<int>done(n);
	for(int i=0;i<n;++i)done.update(i,1);
	for(int j=0;j<n;++j){
		assert(nxt[a[j]]!=n);
		res+=done.query(nxt[a[j]]-1);
		done.update(nxt[a[j]],-1);
		while(++nxt[a[j]]<n&&b[nxt[a[j]]]!=a[j]){}
	}
//	for(int i=0;i<n;++i)cout<<pm[b[i]];
//	cout<<"\n";
//	cerr<<res<<endl;
	return res;
}

pair<ll,vector<int>>solve(){
	int cnts[4];
	for(int i=0;i<4;++i)cnts[i]=count(a.begin(),a.end(),i);
	vector<int>per={0,1,2,3};
	pair<ll,vector<int>>res={-1,{}};
	vector<int>tr(n);
	do{
		int idx=0;
		for(int i=0;i<4;++i)
			for(int j=0;j<cnts[per[i]];++j,++idx)
				tr[idx]=per[i];
		assert(idx==n);
		if(ll op=opers(tr);op>res.first)res={op,tr};
	}while(next_permutation(per.begin(),per.end()));
	return res;
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		n=s.size();
		a.resize(n);
		for(int i=0;i<n;++i)a[i]=mp[s[i]];
		auto[mvs,res]=solve();
		for(int i=0;i<n;++i)cout<<pm[res[i]];
		cout<<"\n";
	}
}