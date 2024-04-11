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

int N;
int ret[202];
vector<int> P;

int ask(vector<int> A) {
	cout<<"?";
	FORR(a,A) cout<<" "<<a;
	cout<<endl;
	
	
	if(P.size()) {
		int i;
		map<int,int> M;
		FOR(i,N) {
			A[i]+=P[i];
			M[A[i]]++;
		}
		FOR(i,N) if(M[A[i]]>1) return i+1;
		return 0;
	}
	
	int x;
	cin>>x;
	return x;
}
void ans() {
	cout<<"!";
	int i;
	FOR(i,N) cout<<" "<<ret[i];
	cout<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==2) {
		x=ask({1,2});
		if(x) {
			ret[0]=2;
			ret[1]=1;
		}
		else {
			ret[0]=1;
			ret[1]=2;
		}
		ans();
	}
	
	// find last;
	for(i=1;i<=N-1;i++) {
		vector<int> V(N,N);
		V[N-1]=i;
		x=ask(V);
		if(x) {
			ret[N-1]=N+1-i;
			break;
		}
	}
	if(i==N) ret[N-1]=1;
	
	for(i=1;i<=N;i++) if(i!=ret[N-1]) {
		vector<int> V(N,ret[N-1]);
		V[N-1]=i;
		x=ask(V);
		assert(x);
		ret[x-1]=i;
	}
	ans();
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}