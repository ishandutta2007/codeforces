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
int A[202020];
int last[202020];
set<int> cand,did;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cand.insert(i+1);
	MINUS(last);
	FOR(i,N) {
		cin>>A[i];
		cand.erase(A[i]);
		last[A[i]]=i;
	}
	
	int num=0;
	FOR(i,N) {
		if(last[A[i]]==i && did.count(A[i])==0) {
			did.insert(A[i]);
		}
		else {
			int c=cand.empty()?N+1:*cand.begin();
			
			if(did.count(A[i]) || c<A[i]) {
				num++;
				A[i]=c;
				cand.erase(c);
			}
			else {
				did.insert(A[i]);
			}
		}
	}
	_P("%d\n",num);
	FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}