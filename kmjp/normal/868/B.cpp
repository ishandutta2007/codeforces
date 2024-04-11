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

int H,M,S,T1,T2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>M>>S>>T1>>T2;
	H%=12;
	T1%=12;
	T2%=12;
	H*=10;
	T1*=10;
	T2*=10;
	M*=2;
	S*=2;
	if(M+S>0) H++;
	if(S) M++;
	if(T1>T2) swap(T1,T2);
	
	int num=0;
	if(T1<H && H<T2) num++;
	if(T1<M && M<T2) num++;
	if(T1<S && S<T2) num++;
	if(num==0 || num==3) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}