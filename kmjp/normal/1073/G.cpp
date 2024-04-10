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

int N,Q;
string S;

struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; string S;
	
	SuffixArray(string S) : S(S){
		int i,h=0; vector<int> tmp;
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
		lcp.resize(N+1); rsa.resize(N+1);
		FOR(i,N+1) rsa[sa[i]]=i;
		FOR(i,N) {
			int j=sa[rsa[i]-1];
			for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
			lcp[rsa[i]-1]=h;
		}
	}
};
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

SuffixArray SA("");
SegTree_1<int,1<<20> st;

ll hoge(vector<pair<int,int>> V) {
	sort(ALL(V));
	map<int,int> M;
	ll ret=0;
	int pre=-1;
	ll S=0;
	
	FORR(v,V) {
		int l=N-v.second;
		int m=l;
		if(pre>=0 && pre<v.first) m=st.getval(pre,v.first);
		pre=v.first;
		
		
		while(M.size() && M.rbegin()->first>m) {
			S-=(M.rbegin()->first-m)*M.rbegin()->second;
			M[m]+=M.rbegin()->second;
			M.erase(M.rbegin()->first);
		}
		ret+=S;
		M[l]++;
		S+=l;
	}
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	SA=SuffixArray(S);
	
	FOR(i,N+1) st.update(i,SA.lcp[i]);
	while(Q--) {
		vector<pair<int,int>> A,B,C;
		cin>>x>>y;
		while(x--) {
			cin>>i;
			A.push_back({SA.rsa[i-1],i-1});
			C.push_back({SA.rsa[i-1],i-1});
		}
		while(y--) {
			cin>>i;
			B.push_back({SA.rsa[i-1],i-1});
			C.push_back({SA.rsa[i-1],i-1});
		}
		
		cout<<(hoge(C)-hoge(A)-hoge(B))<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}