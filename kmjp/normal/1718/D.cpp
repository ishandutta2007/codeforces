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

int T;
int N,Q;
int P[303030],A[303030],rev[303030];
int L[303030],R[303030],LC[303030],RC[303030],par[303030];
int mi[303030],ma[303030];
int K;

set<pair<pair<int,int>,int>> C;
vector<pair<int,int>> V;
vector<pair<int,int>> ev,ev2;
multiset<int> cand;
int cnt[3<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		C.clear();
		V.clear();
		ev.clear();
		ev2.clear();
		
		scanf("%d%d",&N,&Q);
		FOR(i,N) {
			scanf("%d",&P[i]);
			P[i]--;
			rev[P[i]]=i;
			LC[i]=RC[i]=-1;
			mi[i]=0;
			ma[i]=1<<30;
			if(P[i]==N-1) {
				if(i) C.insert({{0,i-1},i});
				if(i<N-1) C.insert({{i+1,N-1},i});
				L[i]=0;
				R[i]=N-1;
				par[i]=i;
			}
			else {
				V.push_back({-P[i],i});
			}
		}
		K=0;
		FOR(i,N) {
			scanf("%d",&A[i]);
			if(A[i]==0) K++;
		}
		

		sort(ALL(V));
		FORR2(a,i,V) {
			auto it=C.lower_bound({{i+1,0},0});
			it--;
			auto p=*it;
			C.erase(it);
			L[i]=p.first.first;
			R[i]=p.first.second;
			par[i]=p.second;
			if(i<p.second) LC[p.second]=i;
			else RC[p.second]=i;
			if(i!=L[i]) C.insert({{L[i],i-1},i});
			if(i!=R[i]) C.insert({{i+1,R[i]},i});
		}
		
		FOR(i,N) {
			x=rev[i];
			mi[x]=1;
			if(LC[x]>=-1) mi[x]=max(mi[x],mi[LC[x]]+1);
			if(RC[x]>=-1) mi[x]=max(mi[x],mi[RC[x]]+1);
			if(A[x]) mi[x]=max(mi[x],A[x]);
		}
		for(i=N-1;i>=0;i--) {
			x=rev[i];
			ma[x]=2<<20;
			if(i<N-1) ma[x]=min(ma[x],ma[par[x]]-1);
			if(A[x]) ma[x]=min(ma[x],A[x]);
		}
		
		/*
		FOR(i,N) {
			cout<<i<<" "<<P[i]<<" "<<A[i]<<" "<<L[i]<<" "<<R[i]<<" "<<LC[i]<<" "<<RC[i]<<" "<<mi[i]<<" "<<ma[i]<<endl;
		}
		*/
	
		
		int ng=0;
		FOR(i,N) {
			if(mi[i]>ma[i]) ng=1;
			if(A[i]==0) {
				ev.push_back({mi[i],ma[i]});
				ev.push_back({ma[i],(1<<30)+3});
				ev2.push_back({-ma[i],mi[i]});
				ev2.push_back({-mi[i],(1<<30)+3});
				cnt[mi[i]]=cnt[ma[i]]=0;
			}
		}
		FOR(i,K-1) {
			scanf("%d",&x);
			ev.push_back({x,(1<<30)+2});
			ev2.push_back({-x,(1<<30)+2});
		}
		
		int TL=-1,TR=-1;
		cand.clear();
		sort(ALL(ev));
		sort(ALL(ev2));
		FORR2(a,c,ev) if(ng==0) {
			if(c==(1<<30)+2) {
				if(cand.empty()) {
					ng=1;
				}
				else {
					cnt[*cand.begin()]++;
					cand.erase(cand.begin());
				}
			}
			else if(c==(1<<30)+3) {
				if(cnt[a]) {
					cnt[a]--;
				}
				else {
					cand.erase(cand.find(a));
					if(TR==-1) {
						TR=a;
					}
					else {
						ng=4;
					}
				}
			}
			else {
				cand.insert(c);
			}
		}
		cand.clear();
		FORR2(a,c,ev) cnt[a]=0;
		
		FORR2(a,c,ev2) if(ng==0) {
			if(c==(1<<30)+2) {
				if(cand.empty()) {
					ng=1;
				}
				else {
					cnt[*cand.rbegin()]++;
					cand.erase(cand.find(*cand.rbegin()));
				}
			}
			else if(c==(1<<30)+3) {
				
				if(cnt[-a]) {
					cnt[-a]--;
				}
				else {
					cand.erase(cand.find(-a));
					if(TL==-1) {
						TL=-a;
					}
					else {
						ng=1;
					}
				}
			}
			else {
				cand.insert(c);
			}
		}
		
		
		FOR(i,Q) {
			scanf("%d",&x);
			if(ng||x<TL||x>TR) {
				_P("NO\n");
			}
			else {
				_P("YES\n");
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}