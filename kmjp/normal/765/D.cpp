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

int N;
int F[101010];
vector<int> from[101010];
int rev[101010],to[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>F[i+1];
		from[F[i+1]].push_back(i+1);
	}
	int num=0;
	FOR(i,N) if(from[i+1].size()) {
		if(count(ALL(from[i+1]),i+1)==0) return _P("-1\n");
		to[i+1]=num+1;
		rev[num++]=i+1;
	}
	_P("%d\n",num);
	FOR(i,N) _P("%d ",to[F[i+1]]);
	_P("\n");
	FOR(i,num) _P("%d ",rev[i]);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}