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


int T,N;
string S;
int A[202020];

int ok(string S2) {
	int cur=0;
	FORR(c,S2) {
		if(c=='(') cur++;
		else cur--;
		if(cur<0) return 0;
	}
	return cur==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int mi=0;
		FOR(i,2*N) {
			A[i+1]=A[i]+(S[i]=='('?1:-1);
			mi=min(mi,A[i+1]);
		}
		if(mi==0) {
			cout<<0<<endl;
			continue;
		}
		int L=0,R=2*N-1;
		FOR(i,2*N) {
			if(A[i]>=A[L]) L=i;
			if(A[i]<0) break;
		}
		for(i=2*N;i>=0;i--) {
			if(A[i]>=A[R]) R=i;
			if(A[i]<0) break;
		}
		string S2=S;
		reverse(S2.begin()+L,S2.begin()+R);
		if(ok(S2)) {
			cout<<1<<endl;
			cout<<(L+1)<<" "<<R<<endl;
			continue;
		}
		x=max_element(A,A+2*N+1)-A;
		cout<<2<<endl;
		cout<<1<<" "<<x<<endl;
		cout<<x+1<<" "<<(2*N)<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}