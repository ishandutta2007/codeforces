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
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int N,Q;
string S[202000];
string sum;
int ind[202000];
int QL[505050],QR[505050],QK[505050];
int A[205050],B[205050],ret[505050];

int rmq[20][1<<21];
BIT<int,19> bt;
vector<int> evs[505050],eve[505050];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	sum.reserve(405000);
	FOR(i,N) {
		cin>>S[i];
		ind[i]=sum.size();
		sum+=S[i]+" ";
	}
	ind[N]=sum.size();
	
	SuffixArray sa(sum);
	FOR(i,sum.size()+1) rmq[0][i]=sa.lcp[i];
	FOR(i,19) FOR(x,sum.size()+1) rmq[i+1][x]=min(rmq[i][x],rmq[i][x+(1<<i)]);
	
	//FOR(i,sum.size()+1) _P("%d %d %d %d [%s]\n",i,sa.rank[i],sa.sa[i],sa.lcp[i],sum.substr(sa.sa[i]).c_str());
	FOR(i,N) {
		A[i]=B[i]=x=sa.rank[ind[i]];
		for(j=19;j>=0;j--) {
			if(A[i]-(1<<j)>=0 && rmq[j][A[i]-(1<<j)]>=S[i].size()) A[i]-=(1<<j);
			if(B[i]+(1<<j)<=sum.size() && rmq[j][B[i]]>=S[i].size()) B[i]+=(1<<j);
		}
	}
	
	FOR(i,Q) {
		cin>>QL[i]>>QR[i]>>QK[i];
		QL[i]--;QR[i]--;QK[i]--;
		evs[ind[QL[i]]].push_back(i);
		eve[ind[QR[i]+1]].push_back(i);
	}
	
	FOR(i,sum.size()+1) {
		FORR(r,evs[i]) ret[r] -= bt.total(B[QK[r]]+1)-bt.total(A[QK[r]]);
		FORR(r,eve[i]) ret[r] += bt.total(B[QK[r]]+1)-bt.total(A[QK[r]]);
		bt.add(sa.rank[i]+1,1);
	}
	
	FOR(i,Q) _P("%d\n",ret[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}