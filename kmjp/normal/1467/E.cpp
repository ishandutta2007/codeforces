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

int N;
int A[202020];
vector<int> E[202020];
map<int,set<int>> M;
int id,L[202020],R[202020],re[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs(int cur,int pre) {
	re[id]=cur;
	L[cur]=id++;
	M[A[cur]].insert(L[cur]);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	
	
	FORR(m,M) {
		set<int> S=m.second;
		if(S.size()==1) continue;
		FORR(s,S) {
			int cur=re[s];
			bt.add(L[cur],1);
			bt.add(L[cur]+1,-1);
			
			if(*S.begin()<s || R[cur]<=*S.rbegin()) {
				bt.add(L[cur],1);
				bt.add(R[cur],-1);
			}
			FORR(e,E[cur]) if(L[e]>L[cur]) {
				auto it=S.lower_bound(L[e]);
				if(it!=S.end() && *it<R[e]) {
					bt.add(0,1);
					bt.add(L[e],-1);
					bt.add(R[e],1);
				}
			}
		}
	}
	int ret=N;
	FOR(i,N) if(bt(i)>0) ret--;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}