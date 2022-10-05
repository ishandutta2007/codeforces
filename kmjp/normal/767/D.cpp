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

int N,M,K;
int F[1010101];
pair<int,int> S[1010101];

int ok(int num) {
	if(num>M) return 0;
	
	int day=0;
	int x=0,y=M-num,i;
	while(x<N || y<M) {
		FOR(i,K) {
			if(x==N && y==M) return 1;
			if(x!=N && (y==M || F[x]<S[y].first)) {
				if(F[x]<day) return 0;
				x++;
			}
			else {
				if(S[y].first<day) return 0;
				y++;
			}
		}
		day++;
	}
	return (x==N && y==M);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>F[i];
	sort(F,F+N);
	FOR(i,M) {
		cin>>S[i].first;
		S[i].second=i;
	}
	sort(S,S+M);
	
	int ret=0;
	if(!ok(0)) return _P("-1\n");
	for(i=19;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	
	vector<int> R;
	FOR(i,ret) R.push_back(S[M-1-i].second+1);
	sort(ALL(R));
	_P("%d\n",R.size());
	FORR(r,R) _P("%d ",r);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}