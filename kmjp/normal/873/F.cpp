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

struct SuffixArray {
	int N; vector<int> rank,lcp,sa; string S;
	
	SuffixArray(string S) : S(S){
		int i,h=0; vector<int> tmp,tr;
		N=S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
		FOR(i,N+1) sa[i]=i, rank[i]=i==N?-1:S[i];
		
		for(int k=1; k<=N; k<<=1) {
			auto pred2 = [k,this](int& a,int &b)->bool{ return (((a+k<=N)?rank[a+k]:-1)<((b+k<=N)?rank[b+k]:-1));};
			auto pred = [pred2,k,this](int& a,int &b)->bool{ return (rank[a]!=rank[b])?(rank[a]<rank[b]):pred2(a,b);};
			int x=0;
			if(k!=1) for(i=1;i<N+1;i++) if(rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x=i;
			sort(sa.begin()+x,sa.end(),pred);
			FOR(i,N+1) tmp[sa[i]]=(i==0)?0:tmp[sa[i-1]]+pred(sa[i-1],sa[i]);
			swap(rank,tmp);
		}
		lcp.resize(N+1); tr.resize(N+1);
		FOR(i,N+1) tr[sa[i]]=i;
		FOR(i,N) {
			int j=sa[tr[i]-1];
			for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
			lcp[tr[i]-1]=h;
		}
	}
};

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,0);};
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
SegTree_1<int,1<<20> st;
int N;
string S,T;

int LCP[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	reverse(ALL(S));
	reverse(ALL(T));
	SuffixArray SA(S);
	
	ll ma=0;
	for(i=1;i<=N;i++) {
		LCP[i]=SA.lcp[i];
		st.update(i,LCP[i]);
		bt.add(i,T[SA.sa[i]]=='0');
		if(T[SA.sa[i]]=='0') ma=max(ma,(ll)(N-SA.sa[i]));
	}
	
	for(i=1;i<=N;i++) if(LCP[i]>0) {
		int R=i,L=i;
		for(j=18;j>=0;j--) if(st.getval(i,R+(1<<j))>=LCP[i]) R+=1<<j;
		for(j=18;j>=0;j--) if(L-(1<<j)>=0 && st.getval(L-(1<<j),i)>=LCP[i]) L-=1<<j;
		ma=max(ma,1LL*LCP[i]*(bt(R)-bt(L-1)));
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}