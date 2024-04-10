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


int T;
int N,X,Y;
int C[101010];
int A[101010];
int B[101010];
vector<int> M[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y;
		int ma=0;
		FOR(i,N+2) M[i].clear();
		
		FOR(i,N) {
			cin>>A[i];
			B[i]=-1;
			M[A[i]].push_back(i);
		}
		set<pair<int,int>> cand;
		FOR(i,N+2) cand.insert({-(int)M[i].size(),i});
		int emp=0;
		for(i=1;i<=N+1;i++) if(M[i].empty()) emp=i;
		
		while(X) {
			X--,Y--;
			x=cand.begin()->second;
			cand.erase(cand.begin());
			y=M[x].back();
			B[y]=A[y];
			M[x].pop_back();
			cand.insert({-(int)M[x].size(),x});
		}
		
		vector<int> step;
		FORR(m,cand) {
			FORR(c,M[m.second]) step.push_back(c);
		}
		
		Y=step.size()-Y;
		
		FOR(i,step.size()) {
			B[step[(i+step.size()/2)%step.size()]]=A[step[i]];
		}
		FORR(s,step) if(A[s]==B[s] && Y) B[s]=emp, Y--;
		FORR(s,step) if(B[s]!=emp && Y) B[s]=emp, Y--;
		
		
		int ng=0;
		FORR(s,step) if(A[s]==B[s]) ng=1;
		if(ng==0) {
			cout<<"YES"<<endl;
			FOR(i,N) cout<<B[i]<<" ";
			cout<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}