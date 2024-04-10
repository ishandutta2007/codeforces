#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
int A[202020];
vector<int> E[202020];
set<int> S[202020];

int hoge(int turn) {
	int i;
	if(N==1) return 1;
	queue<int> Q,nex;
	FOR(i,N) {
		S[i].clear();
		FORR(e,E[i]) S[i].insert(e);
		if(E[i].size()==1) {
			if(A[i]==0||A[i]==turn+1) Q.push(i);
			else nex.push(i);
		}
	}
	
	int num=0;
	while(Q.size()||nex.size()) {
		num++;
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			FORR(e,E[x]) {
				S[e].erase(x);
				if(S[e].size()==1) {
					if(A[e]==0||A[e]==turn+1) Q.push(e);
					else nex.push(e);
				}
			}
		}
		
		swap(nex,Q);
		turn^=1;
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		cout<<min(hoge(0),hoge(1))<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}