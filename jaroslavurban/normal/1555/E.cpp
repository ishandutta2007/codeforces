#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// seg tree for one operation
template<class O>
struct SegmentTree{
	using T=typename O::T;
	int n;vector<T>tr,lz;
	SegmentTree(vector<T>a):n(1<<int(1+log2(a.size()))),tr(2*n,O::D),lz(2*n,O::DL){
		copy(a.begin(),a.end(),tr.begin()+n);
		for(int i=n-1;i>0;--i)tr[i]=O::uni(tr[2*i],tr[2*i+1]);
	}
	void applylazy(int u,int lb,int rb){
		if(lz[u]!=O::DL){
			tr[u]=O::rv(tr[u],lz[u],lb,rb);
			O::upd(lz[2*u],lz[u]);
			O::upd(lz[2*u+1],lz[u]);
			lz[u]=O::DL;
		}
	}
	T query(int l,int r){return query(l,r,0,n,1);}
	T query(int l,int r,int lb,int rb,int u){
		if(rb<=l||r<=lb)return O::D;
		if(l<=lb&&rb<=r)return O::rv(tr[u],lz[u],lb,rb);
		applylazy(u,lb,rb);
		int m=(lb+rb)/2;
		return O::uni(query(l,r,lb,m,2*u),query(l,r,m,rb,2*u+1));
	}
	T update(int l,int r,T x){return update(l,r,0,n,1,x);}
	T update(int l,int r,int lb,int rb,int u,T x){
		if(rb<=l||r<=lb)return O::rv(tr[u],lz[u],lb,rb);
		if(l<=lb&&rb<=r)return O::rv(tr[u],O::upd(lz[u],x),lb,rb);
		applylazy(u,lb,rb);
		int m=(lb+rb)/2;
		return tr[u]=O::uni(update(l,r,lb,m,2*u,x),update(l,r,m,rb,2*u+1,x));
	}
};

// if you get undefined reference to DL, just also put this outside of the struct
// const int max_add::D,max_add::DL;
struct min_add{
	typedef int T;
	static const T D=numeric_limits<T>::max(),DL=0;
	static T rv(T val,T lz,int lb,int rb){return val+lz;}
	static T upd(T&a,T b){return a+=b;}
	static T uni(T a,T b){return min(a,b);}
};
const int min_add::D,min_add::DL;

struct S{
	int l,r,w;
};

void ProGamerMove(){
	int n,m;cin>>n>>m;
	SegmentTree<min_add>st=SegmentTree<min_add>(vector<int>(m));
	vector<S>segs(n);
	for(auto&[l,r,w]:segs)cin>>l>>r>>w,--l,--r;
	sort(segs.begin(),segs.end(),[&](S&a,S&b){
		return a.w<b.w;
	});
	int rg=0,res=INT_MAX;
	for(int lf=0;lf<n;++lf){
		while(rg<n&&!st.query(0,m-1)){
			auto[l,r,w]=segs[rg++];
//			cerr<<lf<<" "<<rg<<" updating "<<l<<" "<<r<<" "<<w<<endl;
			st.update(l,r,+1);
		}
		if(!st.query(0,m-1))break;
//		cerr<<segs[rg-1].w<<" "<<segs[lf].w<<endl;
		res=min(res,segs[rg-1].w-segs[lf].w);
		st.update(segs[lf].l,segs[lf].r,-1);
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}