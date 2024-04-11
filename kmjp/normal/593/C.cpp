#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[100][2],R[100];
string S[100][2];

string hoge(int i,int x) {
	char h[1010];
	sprintf(h,"(%d*((((0-abs((t-%d)))-abs((t-%d)))+abs(((t-%d)-1)))+abs(((t-%d)+1))))",x,i,i,i,i);
	return string(h);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i][0]>>X[i][1]>>R[i];
	FOR(j,2) {
		FOR(i,N) S[i][j]=hoge(i,X[i][j]/2);
		s = S[0][j];
		for(i=1;i<N;i++) s="("+s+"+"+S[i][j]+")";
		cout<<s<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}