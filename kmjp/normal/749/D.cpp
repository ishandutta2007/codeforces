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
int A[202020],B[202020];
int Q;
vector<int> V,fix;
vector<pair<int,int>> P[202020];
int ret[202020];
int del[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i], A[i]--;
		P[A[i]].push_back({B[i],i});
	}
	priority_queue<pair<int,int>> PQ;
	FOR(i,N) if(P[i].size()) PQ.push({P[i].back().first,i});
	
	MINUS(del);
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		V.resize(x);
		FOR(j,x) {
			cin>>V[j], V[j]--;
			del[V[j]]=i;
		}
		
		pair<int,int> k={-1,-1};
		while(PQ.size()) {
			k=PQ.top();
			PQ.pop();
			fix.push_back(k.second);
			if(del[k.second]!=i) break;
			k={-1,-1};
		}
		if(k.first==-1) {
			cout<<"0 0"<<endl;
			goto out;
		}
		
		while(PQ.size()) {
			if(del[PQ.top().second]!=i) break;
			fix.push_back(PQ.top().second);
			PQ.pop();
		}
		if(PQ.empty()) {
			ret[i]=P[k.second][0].second;
		}
		else {
			auto k2=PQ.top();
			int v=k2.first;
			ret[i]=lower_bound(P[k.second].begin(),P[k.second].end(),k2)->second;
		}
		cout<<A[ret[i]]+1<<" "<<B[ret[i]]<<endl;
		out:
		FORR(f,fix) PQ.push({P[f].back().first,f});
		fix.clear();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}