#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

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

int P[26],Q[26];
string S,T;
bitset<204800> BS,BT[26];

int A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,26) {
		cin>>P[i];
		P[i]--;
		Q[P[i]]=i;
	}
	cin>>S>>T;
	FORR(c,S) c-='a';
	FORR(c,T) c-='a';
	
	A=S.size();
	B=T.size();
	FOR(i,B) BT[T[i]][i]=BT[Q[T[i]]][i]=1;
	FOR(i,B-A+1) BS[i]=1;
	FOR(i,A) BS&=BT[S[i]]>>i;
	FOR(i,B-A+1) cout<<BS[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}