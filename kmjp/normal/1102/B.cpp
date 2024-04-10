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

int N,K;
int A[5050];
vector<int> C[5050];
int R[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		C[A[i]].push_back(i);
	}
	for(i=1;i<=5000;i++) {
		if(C[i].size()>K) return _P("NO\n");
		reverse(ALL(C[i]));
	}
	x=0;
	FOR(i,5050) {
		FOR(j,5010) {
			if(C[i].size()) {
				R[C[i].back()]=x+1;
				x=(x+1)%K;
				C[i].pop_back();
			}
		}
	}
	cout<<"YES"<<endl;
	FOR(i,N) cout<<R[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}