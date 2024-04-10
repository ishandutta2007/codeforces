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
string S,T;
queue<int> A[27],B[27];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	FOR(i,N) {
		if(S[i]=='?') A[26].push(i+1);
		else A[S[i]-'a'].push(i+1);
		if(T[i]=='?') B[26].push(i+1);
		else B[T[i]-'a'].push(i+1);
	}
	
	vector<pair<int,int>> V;
	FOR(i,26) {
		while(A[i].size() && B[i].size()) {
			V.push_back({A[i].front(),B[i].front()});
			A[i].pop();
			B[i].pop();
		}
	}
	FOR(i,26) {
		while(A[i].size() && B[26].size()) {
			V.push_back({A[i].front(),B[26].front()});
			A[i].pop();
			B[26].pop();
		}
		while(A[26].size() && B[i].size()) {
			V.push_back({A[26].front(),B[i].front()});
			A[26].pop();
			B[i].pop();
		}
	}
	while(A[26].size() && B[26].size()) {
		V.push_back({A[26].front(),B[26].front()});
		A[26].pop();
		B[26].pop();
	}
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}