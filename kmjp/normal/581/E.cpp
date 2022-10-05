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

int E,S,N,M;
set<int> POS;
map<int,int> G;
map<int,vector<int> > C;
map<int,pair<ll,ll> > gas;
map<int,ll > need;
pair<ll,ll> ret[202000];
vector<int> P[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>E>>S>>N>>M;
	FOR(i,N) {
		cin>>r>>x;
		if(x>=E) continue;
		G[E-x] = max(G[E-x],r);
		POS.insert(E-x);
	}
	
	G[0]=3;
	P[1].push_back(0);
	P[2].push_back(0);
	FORR(r,G) P[r.second].push_back(r.first);
	gas[0]={0,0};
	need[0]=0;
	
	FOR(i,M) {
		cin>>x;
		C[E-x].push_back(i);
		POS.insert(E-x);
	}
	
	vector<int>::iterator pre[4],last[4];
	for(i=1;i<=3;i++) pre[i]=last[i]=P[i].begin();
	
	FORR(r,POS) {
		for(i=1;i<=3;i++) while(pre[i]!=P[i].end() && r-*pre[i]>S) pre[i]++;
		
		int t = G[r];
		if(t) {
			gas[r]={1LL<<40,1LL<<40};
			
			if(t==3) {
				need[r]=0;
				if(last[3]!=P[3].end() && r-*last[3]<=S) {
					gas[r] = gas[*last[3]];
				}
				else if(pre[2]!=P[2].end() && *pre[2]<r) {
					int left=S-(r-*pre[2]);
					gas[r] = {gas[*pre[2]].first,gas[*pre[2]].second + max(0LL,need[*pre[2]]-left)};
				}
				else if(pre[1]!=P[1].end() && *pre[1]<r) {
					int left=S-(r-*pre[1]);
					gas[r] = {gas[*pre[1]].first + max(0LL,need[*pre[1]]-left) ,gas[*pre[1]].second };
				}
			}
			else if(t==2) {
				if(last[3]!=P[3].end() && r-*last[3]<=S) {
					gas[r] = gas[*last[3]];
					need[r]= r-*last[3];
				}
				else if(last[2]!=P[2].end() && r-*last[2]<=S) {
					gas[r] = gas[*last[2]];
					gas[r].second += need[*last[2]];
					need[r]= r-*last[2];
				}
				else if(pre[1]!=P[1].end() && *pre[1]<r) {
					int left=S-(r-*pre[1]);
					gas[r] = {gas[*pre[1]].first + max(0LL,need[*pre[1]]-left) ,gas[*pre[1]].second };
					need[r]= S;
				}
			}
			else if(t==1) {
				int mi=4;
				for(i=3;i>=1;i--) if(last[i]!=P[i].end() && (mi==4 || *last[i]>*last[mi]) && r-*last[i]<=S) mi=i;
				if(mi!=4) {
					gas[r] = gas[*last[mi]];
					if(mi==1) gas[r].first += need[*last[mi]];
					if(mi==2) gas[r].second += need[*last[mi]];
					need[r]= r-*last[mi];
				}
				
			}
			last[t]++;
		}
		
		if(C.count(r)) {
			pair<ll,ll> tret={1LL<<40,1LL<<40};
			if(last[3]!=P[3].end() && r-*last[3]<=S) {
				tret = gas[*last[3]];
			}
			else if(pre[2]!=P[2].end() && *pre[2]<r) {
				int left=S-(r-*pre[2]);
				tret = {gas[*pre[2]].first,gas[*pre[2]].second + max(0LL,need[*pre[2]]-left)};
			}
			else if(pre[1]!=P[1].end() && *pre[1]<r) {
				int left=S-(r-*pre[1]);
				tret = {gas[*pre[1]].first + max(0LL,need[*pre[1]]-left) ,gas[*pre[1]].second };
			}
			if(tret.first>=1LL<<40) tret.first=tret.second=-1;
			FORR(r2,C[r]) ret[r2]=tret;
		}
	}
	
	FOR(i,M) _P("%d %d\n",(int)ret[i].first,(int)ret[i].second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}