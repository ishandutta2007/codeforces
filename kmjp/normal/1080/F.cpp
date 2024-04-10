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

int N,M,K;
const int DI=350;
vector<pair<int,int>> V[101010];
vector<vector<int>> V2[350];
int st[101010];

int check(int v,int L,int R) {
	int a=lower_bound(ALL(V[v]),make_pair(L,0))-V[v].begin();
	if(a==V[v].size()) return 0;
	return V[v][a].second<=R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>x>>y>>k;
		k--;
		V[k].push_back({x,y});
	}
	int cur=0;
	FOR(i,N) if(V[i].size()) {
		sort(ALL(V[i]));
		for(j=V[i].size()-2;j>=0;j--) V[i][j].second=min(V[i][j].second,V[i][j+1].second);
		FORR(v,V[i]) V2[i/DI].push_back({v.first,v.second,i%DI});
	}
	FOR(i,DI) if(V2[i].size()) {
		sort(ALL(V2[i]));
		deque<int> DQ[DI];
		multiset<int> M;
		
		for(int L=0,R=0;L<V2[i].size();L++) {
			while(R<V2[i].size() && M.size()<DI) {
				auto v=V2[i][R++];
				DQ[v[2]].push_back(v[1]);
				if(DQ[v[2]].size()==1) M.insert(v[1]);
			}
			if(M.size()<DI) V[N+i].push_back({V2[i][L][0],1<<30});
			else V[N+i].push_back({V2[i][L][0],*M.rbegin()});
			
			x=V2[i][L][2];
			M.erase(M.find(DQ[x].front()));
			DQ[x].pop_front();
			if(DQ[x].size()) M.insert(DQ[x].front());
		}
	}
	while(M--) {
		int A,B,L,R;
		cin>>A>>B>>L>>R;
		A--;
		int ok=1;
		while(ok==1 && A<B && A%DI) ok&=check(A++,L,R);
		while(ok==1 && A<B && B%DI) ok&=check(--B,L,R);
		while(ok==1 && A<B) ok&=check(N+A/DI,L,R), A+=DI;
		
		if(ok) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}