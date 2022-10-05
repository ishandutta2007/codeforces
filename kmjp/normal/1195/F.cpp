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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

vector<pair<int,int>> V[101010];
vector<int> nex[101010];
map<pair<int,int>,int> M;
int L[101010],R[101010];
vector<int> ev[101010];
int ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		vector<pair<int,int>> P(x);
		FOR(j,x) cin>>P[j].first>>P[j].second;
		P.push_back(P[0]);
		FOR(j,x) {
			int dx=P[j+1].first-P[j].first;
			int dy=P[j+1].second-P[j].second;
			int g=__gcd(abs(dx),abs(dy));
			V[i].push_back({dx/g,dy/g});
		}
	}
	for(i=N-1;i>=0;i--) {
		FORR(v,V[i]) {
			if(M.count(v)) {
				nex[i].push_back(M[v]);
			}
			else {
				nex[i].push_back(N);
			}
			M[v]=i;
		}
	}
	FORR(m,M) bt.add(m.second,1);
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ev[L[i]].push_back(i);
	}
	
	FOR(i,N) {
		FORR(e,ev[i]) ret[e]=bt(R[e]-1)-bt(i-1);
		FORR(e,nex[i]) bt.add(e,1);
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}