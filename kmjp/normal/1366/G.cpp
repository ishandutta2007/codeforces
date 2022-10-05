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
int N,M;
int nex[101010];
int memo[10101][10101];
map<int,int> mm;

int hoge(int A,int B) {
	if(memo[A][B]>=0) return memo[A][B];
	
	if(A==N) {
		if(B==M) return 0;
		return 1<<30;
	}
	
	int ret=1+hoge(A+1,B);
	if(B<M && S[A]==T[B]) ret=min(ret,hoge(A+1,B+1));
	if(S[A]=='.' && B) ret=min(ret,hoge(A+1,B-1));
	if(S[A]!='.' && nex[A]!=-1) ret=min(ret,hoge(nex[A],B));
	
	return memo[A][B]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	M=T.size();
	
	mm[0]=N;
	int cur=0;
	for(i=N-1;i>=0;i--) {
		if(S[i]=='.') cur--;
		else cur++;
		if(mm.count(cur)) nex[i]=mm[cur];
		else nex[i]=-1;
		mm[cur]=i;
	}
	MINUS(memo);
	cout<<hoge(0,0)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}