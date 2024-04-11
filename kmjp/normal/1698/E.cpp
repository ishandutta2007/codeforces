#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,S;
int A[202020];
int B[202020];
int C[202020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		MINUS(B);
		set<int> need;
		FOR(i,N) {
			cin>>x;
			if(x!=-1) {
				B[A[i]]=x-1;
				need.insert(x-1);
			}
		}
		ll ret=1;
		int cand=0;
		set<int> C;
		FOR(i,S) {
			if(B[i]==-1) cand++;
			else C.insert(B[i]);
		}
		FOR(i,N) {
			if(i+S<N) {
				if(B[i+S]==-1) cand++;
				else C.insert(B[i+S]);
			}
			if(need.count(i)) {
				if(C.count(i)==0) ret=0;
				C.erase(i);
			}
			else {
				ret=ret*cand%mo;
				cand--;
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}