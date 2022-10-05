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


int A,B,K;
string S,T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>K;
	int N=A+B;
	S=T=string(N,'0');
	if(K==0) {
		S=T=string(B,'1')+string(A,'0');
		cout<<"Yes"<<endl;
		cout<<S<<endl;
		cout<<S<<endl;
		return;
	}
	if(K>N-2) return _P("No\n");
	if(B<2) return _P("No\n");
	if(A==0) return _P("No\n");
	B-=2;
	
	if(B>N-3) return _P("No\n");
	
	S[0]=T[0]='1';
	T[N-1]='1';
	S[N-1-K]='1';
	x=N-1-K;
	FOR(i,N) {
		if(i==0||i==x||i==N-1) continue;
		if(B) B--, S[i]=T[i]='1';
	}
	cout<<"Yes"<<endl;
	cout<<S<<endl;
	cout<<T<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}