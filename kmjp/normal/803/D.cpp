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

int K;
string S;
char buf[1010101];
vector<int> V;

int ok(int ret) {
	int NL=K;
	int buf=0;
	FORR(r,V) {
		if(ret<r) return 0;
		if(buf<r) {
			buf=ret;
			NL--;
		}
		buf-=r;
	}
	return NL>=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d\n",&K);
	gets(buf);
	S=buf;
	reverse(ALL(S));
	int num=0;
	FORR(c,S) {
		if(c==' ' || c=='-') {
			V.push_back(num);
			num=1;
		}
		else num++;
	}
	V.push_back(num);
	
	int ret=(1<<22)-1;
	for(i=21;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}