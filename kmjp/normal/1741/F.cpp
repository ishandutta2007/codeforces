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

int T,N;
int L[202020],R[202020],C[202020];
vector<int> ev[202020];
ll ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
multiset<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) ev[i].clear();
		vector<ll> Xs;
		Xs.push_back(-1LL<<60);
		Xs.push_back(1LL<<60);
		
		FOR(i,N) {
			cin>>L[i]>>R[i]>>C[i];
			C[i]--;
			Xs.push_back(L[i]);
			Xs.push_back(R[i]);
		}
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		M.clear();
		M.insert(0);
		M.insert(Xs.size()-1);
		
		FOR(i,N) {
			L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
			R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
			bt.add(L[i],1);
			bt.add(R[i]+1,-1);
			M.insert(L[i]);
			M.insert(R[i]);
			ev[C[i]].push_back(i);
		}
		FOR(i,N) {
			FORR(e,ev[i]) {
				M.erase(M.find(L[e]));
				M.erase(M.find(R[e]));
				bt.add(L[e],-1);
				bt.add(R[e]+1,1);
			}
			FORR(e,ev[i]) {
				ret[e]=1LL<<60;
				if(bt(L[e])||bt(R[e])) ret[e]=0;
				auto it=M.lower_bound(L[e]);
				if(*it<=R[e]) ret[e]=0;
				else ret[e]=min(ret[e],Xs[*it]-Xs[R[e]]);
				it--;
				ret[e]=min(ret[e],Xs[L[e]]-Xs[*it]);
				
			}
			FORR(e,ev[i]) {
				M.insert(L[e]);
				M.insert(R[e]);
				bt.add(L[e],1);
				bt.add(R[e]+1,-1);
			}
		}
		FOR(i,N) {
			cout<<ret[i]<<" ";
			bt.add(L[i],-1);
			bt.add(R[i]+1,1);
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}