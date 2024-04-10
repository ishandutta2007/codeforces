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

int N;
vector<pair<int,char>> E[402020];

int Q;
vector<int> ev[404040];
vector<string> S;
string RS;
int ind[404040];
ll ret[404040];


struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; string S;
	
	void build(string S){
		this->S=S;
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
SuffixArray sa;

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][*c+1]=V.size()-1;
				cur=V[cur][*c+1];
			}
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
SegTree_1<int,1<<20> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;


class ACmatch_enum {
public:
	Trie t;
	vector<vector<int> > acc;
	int ma;
	void create(vector<string> S) {
		int i,j;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) {
			int st=ind[i];
			int cur=0;
			FOR(j,S[i].size()) {
				cur=t.V[cur][S[i][j]+1];
				int tar=sa.rsa[ind[i]+S[i].size()-1-j];
				if(acc[cur].empty()) acc[cur].push_back(tar);
			}
		}
		queue<int> Q;
		FOR(i,NUMC) if(t.V[0][i+1]) t.V[t.V[0][i+1]][0]=0, Q.push(t.V[0][i+1]);
		
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				int pre=t.V[k][0];
				while(pre && t.V[pre][i+1]==0) pre=t.V[pre][0];
				t.V[t.V[k][i+1]][0]=t.V[pre][i+1];
			}
		}
	}
	
	
	void dfs(int cur,int pos) {
		int i;
		
		FORR(e,ev[cur]) {
			int L=sa.rsa[ind[e]],R=L;
			for(int j=18;j>=0;j--) if(R+(1<<j)<=RS.size() && st.getval(L,R+(1<<j))>=S[e].size()) R+=1<<j;
			for(int j=18;j>=0;j--) if(L-(1<<j)>=0 && st.getval(L-(1<<j),R)>=S[e].size()) L-=1<<j;
			ret[e]=bt(R)-bt(L-1);
		}
			

		FORR(e,E[cur]) {
			int prev=pos;
			while(pos && t.V[pos][e.second+1]==0) pos=t.V[pos][0];
			pos=t.V[pos][e.second+1];
			FORR(r,acc[pos]) bt.add(r,1);
			dfs(e.first,pos);
			FORR(r,acc[pos]) bt.add(r,-1);
			
			pos=prev;
			
		}
	}
};
ACmatch_enum ac;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>j;
		x=0;
		if(j==2) cin>>x;
		cin>>s;
		E[x].push_back({i+1,s[0]-'a'});
	}
	cin>>Q;
	map<string,int> memo;
	FOR(i,Q) {
		cin>>x>>s;
		ev[x].push_back(i);
		FORR(c,s) c-='a';
		S.push_back(s);
		FORR(c,s) c+='a';
		reverse(ALL(s));
		if(memo.count(s)) {
			ind[i]=memo[s];
		}
		else {
			ind[i]=RS.size();
			memo[s]=ind[i];
			RS+=s+"#";
		}
	}
	sa.build(RS);
	FOR(i,RS.size()) st.update(i,sa.lcp[i]);
	
	ac.create(S);
	ac.dfs(0,0);
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}