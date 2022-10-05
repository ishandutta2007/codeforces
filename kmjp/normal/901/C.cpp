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

// SC: BR: ART: add_edge
// BR
class SCC_BI {
public:
	static const int MV = 310000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

SCC_BI bi;
int N,M,Q;
int R[303030];
int X[303030],Y[303030];
ll ret[303030];
const int DI=600;
vector<pair<int,int>> ev[600];
int del[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	bi.init(N);
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		bi.add_edge(x-1,y-1);
	}
	FOR(i,N) R[i]=N-1;
	bi.scc();
	FOR(i,bi.SC.size()) if(bi.SC[i].size()>1) {
		sort(ALL(bi.SC[i]));
		R[bi.SC[i][0]]=bi.SC[i].back()-1;
	}
	for(i=N-2;i>=0;i--) R[i]=min(R[i],R[i+1]);
	
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d%d",&X[i],&Y[i]);
		X[i]--,Y[i]--;
		ev[X[i]/DI].push_back({Y[i],i});
	}
	FOR(i,DI) if(ev[i].size()) {
		ZERO(del);
		sort(ALL(ev[i]));
		int cnt=0;
		ll tot=0;
		int LL=0,RR=-1;
		FORR(e,ev[i]) {
			while(RR<e.first) {
				RR++;
				cnt++;
				tot+=cnt;
				del[R[RR]]++;
				cnt-=del[RR];
			}
			while(LL>X[e.second]) {
				LL--;
				if(R[LL]<=RR) {
					tot+=R[LL]-LL+1;
				}
				else {
					cnt++;
					tot+=RR-LL+1;
					del[R[LL]]++;
				}
			}
			while(LL<X[e.second]) {
				if(R[LL]<=RR) {
					tot-=R[LL]-LL+1;
				}
				else {
					cnt--;
					tot-=RR-LL+1;
					del[R[LL]]--;
				}
				LL++;
			}
			
			ret[e.second]=tot;
		}
		
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}