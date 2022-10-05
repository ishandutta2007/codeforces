#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<int NV> class SegTree_LazyHash {
public:
	ll mo[2];
	int mul[2],add;
	vector<ll> val,to[2];
	vector<ll> fact[2],p[2];
	SegTree_LazyHash(){
		add =239;
		mul[0]=1003,mo[0]=1000000007;
		mul[1]=1009,mo[1]=1000000009;
		int i,j;
		val.resize(NV*2,0);
		FOR(j,2) {
			to[j].resize(NV*2);
			fact[j].resize(NV*2+1,0); p[j].resize(NV*2+1);
			fact[j][0]=0, p[j][0]=1;
			FOR(i,NV*2) fact[j][i+1]=(fact[j][i]*mul[j]+1)%mo[j], p[j][i+1]=p[j][i]*mul[j]%mo[j];
		}
	};

	pair<ll,ll> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(0,0);
		if(x<=l && r<=y) return make_pair(to[0][k],to[1][k]);
		
		x=max(x,l);
		y=min(y,r);
		if(val[k]>=0) return make_pair(val[k]*fact[0][y-x]%mo[0],val[k]*fact[1][y-x]%mo[1]);
		pair<ll,ll> a=getval(x,y,l,(l+r)/2,k*2);
		pair<ll,ll> b=getval(x,y,(l+r)/2,r,k*2+1);
		if((l+r)/2-x>=0) return make_pair((a.first+b.first*p[0][(l+r)/2-x])%mo[0],(a.second+b.second*p[1][(l+r)/2-x])%mo[1]);
		return b;
	}

	void update(int x,int y,ll v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		int i;
		if(x<=l && r<=y) {
			val[k]=v+add;
			FOR(i,2) to[i][k]=fact[i][r-l]*val[k]%mo[i];
		}
		else if(l < y && x < r) {
			if(val[k]!=-1) {
				val[k*2]=val[k*2+1]=val[k];
				FOR(i,2) to[i][k*2]=to[i][k*2+1]=val[k]*fact[i][(r-l)/2]%mo[i];
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			FOR(i,2) to[i][k]=(to[i][k*2]+to[i][k*2+1]*p[i][(r-l)/2])%mo[i];
		}
	}
};

int N,M,K;
string S;
SegTree_LazyHash<1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>S;
	FOR(i,N) st.update(i+1,i+2,S[i]-'0');
	M+=K;
	while(M--) {
		cin>>i>>l>>r>>x;
		if(i==1) {
			st.update(l,r+1,x);
		}
		else {
			if(st.getval(l,r+1-x)==st.getval(l+x,r+1)) _P("YES\n");
			else _P("NO\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}