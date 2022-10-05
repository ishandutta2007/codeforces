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
int N,M;
vector<int> E[202020];
int A[202020],B[202020];
int in[202020];
int order[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+1) E[i].clear(), in[i]=0;
		FOR(i,M) {
			cin>>r>>A[i]>>B[i];
			if(r==1) {
				E[A[i]].push_back(B[i]);
				in[B[i]]++;
			}
		}
		queue<int> Q;
		FOR(i,N) if(in[i+1]==0) Q.push(i+1);
		int processed=0;
		while(Q.size()) {
			x=Q.front();
			order[x]=processed++;
			Q.pop();
			FORR(e,E[x]) {
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
		
		if(processed==N) {
			cout<<"YES"<<endl;
			FOR(i,M) {
				if(order[A[i]]<order[B[i]]) {
					cout<<A[i]<<" "<<B[i]<<endl;
				}
				else {
					cout<<B[i]<<" "<<A[i]<<endl;
				}
			}
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