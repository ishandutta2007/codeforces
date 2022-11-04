#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// seg tree for multiple operations / data
// not really tested / used
// not exactly fast so far
template<class T>
struct ST{
	int n;vector<T>t;
	ST(const vector<T>&a):n(1<<int(1+log2(a.size()))),t(2*n){
		copy(a.begin(),a.end(),t.begin()+n);
		for(int i=n-1;i>0;--i)t[i]=T::uni(t[2*i],t[2*i+1]);
	}
	T query(int l,int r){return query(l,r,0,n,1);}
	T query(int l,int r,int lb,int rb,int u){
		if(rb<=l||r<=lb)return T();
		if(l<=lb&&rb<=r)return T::rv(t[u],lb,rb);
		T::prop(t[u],t[2*u],t[2*u+1],lb,rb);
		int m=(lb+rb)/2;
		return T::uni(query(l,r,lb,m,2*u),query(l,r,m,rb,2*u+1));
	}
	T update(int l,int r,T x){return update(l,r,0,n,1,x);}
	T update(int l,int r,int lb,int rb,int u,T x){
		if(rb<=l||r<=lb)return T::rv(t[u],lb,rb);
		if(l<=lb&&rb<=r)return T::rv(T::upd(t[u],x,lb,rb),lb,rb);
		T::prop(t[u],t[2*u],t[2*u+1],lb,rb);
		int m=(lb+rb)/2;
		return t[u]=T::uni(update(l,r,lb,m,2*u,x),update(l,r,m,rb,2*u+1,x));
	}
};

struct maxeq{
	typedef int T;
	static const T D=numeric_limits<T>::min(),DL=0;
	T mx,lz,id;
	maxeq(T mx=D,T lz=DL,T id=-1):mx(mx),lz(lz),id(id){}
	// children have no lazy
	static maxeq uni(const maxeq&a,const maxeq&b){
		return maxeq(max(a.mx,b.mx),DL,a.mx<b.mx?b.id:a.id);
	}
	static void prop(maxeq&p,maxeq&l,maxeq&r,int lb,int rb){
		if(p.lz!=DL){
			if(rv(l,lb,rb).mx<=p.lz)tie(l.lz,l.id)=tie(p.lz,p.id);
			if(rv(r,lb,rb).mx<=p.lz)tie(r.lz,r.id)=tie(p.lz,p.id);
			p.mx=p.lz;
			p.lz=DL;
		}
	}
	static maxeq rv(const maxeq&u,int lb,int rb){return maxeq(u.lz?u.lz:u.mx,DL,u.id);}
	// only used once per query
	static maxeq upd(maxeq&u,maxeq&v,int lb,int rb){
		return u=maxeq(u.mx,rv(u,lb,rb).mx<=v.lz?v.lz:u.lz,rv(u,lb,rb).mx<=v.lz?v.id:u.id);
	}
};

struct S{
	int v,i,j,p;
	bool operator<(S a){return v<a.v;}
};

void ProGamerMove(){
	int n,m;cin>>n>>m;
	vector<vector<pair<int,int>>>segs(n);
	vector<S>vals;
	for(int t,l,r,i=0;i<m;++i){
		cin>>t>>l>>r;
		segs[--t].push_back({--l,r});
		vals.push_back({l,t,(int)segs[t].size()-1,0});
		vals.push_back({r,t,(int)segs[t].size()-1,1});
	}
	sort(vals.begin(),vals.end());
	int cur=-1,pr=INT_MIN;
	for(auto[v,i,j,p]:vals){
		if(pr!=v){
			++cur,pr=v;
		}
		if(!p)segs[i][j].first=cur;
		else segs[i][j].second=cur;
	}
	vector<maxeq>tmp(1e6,maxeq(0,0,-1));
	ST<maxeq>st(tmp);
	vector<int>prv(n),stay(n);
	pair<int,int>rs;
	for(int i=0;i<n;++i){
		pair<int,int>res={0,-1};
		for(auto&[l,r]:segs[i]){
			auto q=st.query(l,r);
			res=max(res,{q.mx,q.id});
		}
		for(auto[l,r]:segs[i])st.update(l,r,maxeq(0,res.first+1,i));
		rs=max(rs,make_pair(res.first+1,i));
		prv[i]=res.second;
	}
	for(int i=rs.second;~i;i=prv[i])stay[i]=1;
	cout<<n-rs.first<<"\n";
	for(int i=0;i<n;++i)if(!stay[i])cout<<i+1<<" ";cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}