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

string S,T;
int A,B;
int L[101010],R[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	
	int mi=-2,ma=B+1;
	FOR(i,B) {
		if(i) L[i]=min(A,L[i-1]+1);
		while(L[i]<A && T[i]!=S[L[i]]) L[i]++;
		if(L[i]<A) mi=i,ma=B;
	}
	
	L[B]=A+1;
	for(i=B-1;i>=0;i--) {
		if(i==B-1) R[i]=A-1;
		else R[i]=max(-1,R[i+1]-1);
		while(R[i]>=0 && T[i]!=S[R[i]]) R[i]--;
		if(R[i]<0) break;
		
		x=lower_bound(L,L+B,R[i])-L-1;
		if(x<i) {
			if(x+B-i > mi+B-ma) {
				mi=x;
				ma=i;
			}
		}
	}
	
	if(mi==-2) {
		cout<<"-"<<endl;
	}
	else {
		cout<<T.substr(0,mi+1)<<T.substr(ma)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}