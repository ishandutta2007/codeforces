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


string A,B;
int LA,LB;
int sum[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	LA=A.size();
	LB=B.size();
	FOR(i,LB) FOR(j,2) sum[j][i+1]=sum[j][i]+(B[i]=='0'+j);
	ll ret=0;
	FOR(i,LA) {
		int L=i,R=i+LB-LA;
		ret += sum[(A[i]-'0')^1][R+1]-sum[(A[i]-'0')^1][L];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}