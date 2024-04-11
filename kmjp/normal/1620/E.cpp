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


int Q;
int A[505050],B[505050],C[505050];
int to[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		if(A[i]==2) cin>>C[i];
	}
	FOR(i,505040) to[i]=i;
	vector<int> R;
	for(i=Q-1;i>=0;i--) {
		if(A[i]==1) {
			R.push_back(to[B[i]]);
		}
		else {
			to[B[i]]=to[C[i]];
		}
	}
	reverse(ALL(R));
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}