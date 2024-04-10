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

int T;
int N,M;
string S;
int A[202020];
int mi[202020];
int ma[202020];
int RA[202020];
int Rmi[202020];
int Rma[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>S;
		FOR(i,N) {
			A[i+1]=A[i];
			if(S[i]=='-') A[i+1]--;
			if(S[i]=='+') A[i+1]++;
			mi[i+1]=min(mi[i],A[i+1]);
			ma[i+1]=max(ma[i],A[i+1]);
		}
		RA[N]=Rmi[N]=Rma[N]=0;
		for(i=N-1;i>=0;i--) {
			RA[i]=RA[i+1];
			if(S[i]=='-') {
				RA[i]--;
				Rmi[i]=Rmi[i+1]-1;
				Rma[i]=max(0,Rma[i+1]-1);
			}
			if(S[i]=='+') {
				RA[i]++;
				Rmi[i]=min(0,Rmi[i+1]+1);
				Rma[i]=Rma[i+1]+1;
			}
		}
		while(M--) {
			int L,R;
			cin>>L>>R;
			L--;
			int cmi=min(mi[L],A[L]+Rmi[R]);
			int cma=max(ma[L],A[L]+Rma[R]);
			cout<<(cma+1-cmi)<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}