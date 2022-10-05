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
int A[202020];
int num[2];
vector<int> unfixed;
set<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		if(S.count(A[i]) || num[A[i]%2]>=N/2) {
			unfixed.push_back(i);
		}
		else {
			num[A[i]%2]++;
			S.insert(A[i]);
		}
	}
	x = unfixed.size();
	for(i=1;i<=M && unfixed.size();i++) if(S.count(i)==0 && num[i%2]<N/2) {
		A[unfixed.back()]=i;
		num[i%2]++;
		unfixed.pop_back();
	}
	if(unfixed.size()) return _P("-1\n");
	
	_P("%d\n",x);
	FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}