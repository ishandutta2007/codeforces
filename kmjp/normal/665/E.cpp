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

int N,K;
int A[1010100];
int S[1010100],Q[1010100],R[1010101];
pair<int,int> P[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;

int query(int V,int cur,int mask,int d,int L,int R) {
	if(L>=R) return 0;
	if(d<0) {
		//_P("last %d %d %d %d\n",cur,mask,L,R);
		return 0;
		//return bt(R)-bt(L);
	}
	
	int x=lower_bound(Q+L,Q+R,(cur^mask)+(1<<d))-Q;
	//_P("%d : V:%d cur:%d mask:%d L:%d x:%d R:%d\n",d,V,cur,mask,L,x,R);
	if(cur+(1<<d)>=K) {
		
		if((V>>d)&1) {
			//_P("add %d-%d %d\n",L,x,(bt(x)-bt(L)));
			return (bt(x)-bt(L))+query(V,cur,mask|(1<<d),d-1,x,R);
		}
		else {
			//_P("add %d-%d %d\n",x,R,(bt(R)-bt(x)));
			//_P("hey %d : V=%d cur=%d %d %d %d\n",d,V,cur,L,x,R);
			return (bt(R)-bt(x))+query(V,cur,mask,d-1,L,x);
		}
	}
	else {
		if((V>>d)&1) {
			return query(V,cur+(1<<d),mask|(1<<d),d-1,L,x);
		}
		else {
			return query(V,cur+(1<<d),mask,d-1,x,R);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]^A[i];
		P[i]={S[i],i};
	}
	
	sort(P,P+N);
	FOR(i,N) Q[i]=P[i].first, R[P[i].second]=i;
	ll ret=0;
	FOR(i,N) {
		//_P("%d %d\n",R[i],S[i]);
		bt.add(R[i]+1,1);
		x=query(S[i+1],0,0,30,0,N);
		//_P("re:%d\n",x);
		ret+=x;
	}
	cout<<ret<<endl;
	
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}