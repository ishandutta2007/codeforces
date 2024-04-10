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

int N,M;
int W[202020];
int X[202020],Y[202020];
set<int> C[202020];
int ret[202020];
int did[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>W[i];
	}
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		C[X[i]].insert(i);
		C[Y[i]].insert(i);
	}
	
	vector<int> R;
	queue<int> Q;
	FOR(i,N) if(C[i].size()<=W[i]) did[i]=1,Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		while(C[x].size()) {
			y=*C[x].begin();
			R.push_back(y+1);
			C[X[y]].erase(y);
			C[Y[y]].erase(y);
			if(did[X[y]]==0 && C[X[y]].size()<=W[X[y]]) did[X[y]]=1,Q.push(X[y]);
			if(did[Y[y]]==0 && C[Y[y]].size()<=W[Y[y]]) did[Y[y]]=1,Q.push(Y[y]);
			
		}
	}
	if(R.size()<M) return _P("DEAD\n");
	
	cout<<"ALIVE"<<endl;
	reverse(ALL(R));
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}