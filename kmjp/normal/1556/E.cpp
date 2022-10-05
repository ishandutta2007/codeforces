#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,Q;
ll A[101010],B[101010];


template<int NV> class SegTree_1 {
public:
	vector<pair<ll,ll>> val;
	pair<ll,ll> comp(pair<ll,ll> l,pair<ll,ll> r){
		ll sum=l.first+r.first;
		ll mi=min(l.second,l.first+r.second);
		return {sum,mi};
	};
	
	SegTree_1(){val.resize(NV*2);};
	pair<ll,ll> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, ll v) {
		entry += NV;
		if(v>=0) val[entry]={v,0};
		else val[entry]={v,v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<int NV> class SegTree_2 {
public:
	vector<pair<ll,ll>> val;
	pair<ll,ll> comp(pair<ll,ll> l,pair<ll,ll> r){
		ll sum=l.first+r.first;
		ll mi=max(l.second,l.first+r.second);
		return {sum,mi};
	};
	
	SegTree_2(){val.resize(NV*2);};
	pair<ll,ll> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, ll v) {
		entry += NV;
		if(v>=0) val[entry]={v,v};
		else val[entry]={v,0};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<1<<20> st1;
SegTree_2<1<<20> st2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		A[i]=B[i]-A[i];
		st1.update(i+1,A[i]);
		st2.update(i+1,A[i]);
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		auto a=st1.getval(L+1,R+1);
		auto b=st2.getval(L+1,R+1);
		if(a.first || a.second<0) {
			cout<<-1<<endl;
		}
		else {
			cout<<st2.getval(L+1,R+1).second<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}