#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	SegTree_2(){val.resize(NV*2,1<<30);}
	
	V getval(int entry) {
		entry += NV;
		int ret=1<<30;
		while(entry>0) ret=min(ret,val[entry]), entry>>=1;
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=min(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int N,M;
int T[303030],A[303030],B[303030],C[303030];

int ma[303030];
SegTree_2<int,1<<20> st_mi;
SegTree_1<int,1<<20> st_ma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(ma);
	FOR(i,M) {
		cin>>T[i]>>A[i]>>B[i];
		A[i]--;
		if(T[i]==1) {
			cin>>C[i];
			st_mi.update(A[i],B[i],C[i]);
		}
		else {
			if(ma[A[i]]==-1) ma[A[i]]=st_mi.getval(A[i]);
		}
	}
	FOR(i,N) {
		if(ma[i]==-1) ma[i]=st_mi.getval(i);
		st_ma.update(i,ma[i]);
	}
	
	FOR(i,M) {
		if(T[i]==1) {
			if(st_ma.getval(A[i],B[i])!=C[i]) return _P("NO\n");
		}
		else {
			st_ma.update(A[i],B[i]);
		}
	}
	
	map<int,int> P;
	FOR(i,N) P[ma[i]]++;
	
	_P("YES\n");
	if(P[1<<30]>=2) {
		int first=1;
		FOR(i,N) {
			if(ma[i]==1<<30) {
				if(first) {
					ma[i]=(1<<29)-1;
					first=0;
				}
				else ma[i]=1000000000;
			}
			_P("%d ",ma[i]);
		}
	}
	else {
		int ret=0;
		FOR(i,N) {
			if(ma[i]==0 || ma[i]==1<<30) continue;
			P[ma[i]]--;
			if(P[ma[i]]>0) {
				int x=0;
				while(x*2+1<=ma[i]) x=x*2+1;
				ma[i]=x;
			}
			ret |= ma[i];
		}
		int left=0;
		for(i=29;i>=0;i--) if((ret&(1<<i))==0 && left+(1<<i)<=1000000000) left += 1<<i;
		FOR(i,N) {
			if(ma[i]==1<<30) ma[i]=left;
			_P("%d ",ma[i]);
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}