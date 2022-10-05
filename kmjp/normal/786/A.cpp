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
vector<int> A[2];
int win[2][7070];
int num[2][7070];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>x;
	FOR(i,x) cin>>y, A[0].push_back(y);
	cin>>x;
	FOR(i,x) cin>>y, A[1].push_back(y);
	
	for(i=1;i<N;i++) num[0][i]=A[0].size();
	for(i=1;i<N;i++) num[1][i]=A[1].size();
	
	MINUS(win);
	win[0][0]=win[1][0]=0;
	queue<int> Q;
	Q.push(0);
	Q.push(10000);
	
	while(Q.size()) {
		x = Q.front()%10000;
		y = Q.front()/10000;
		r = y^1;
		Q.pop();
		
		if(win[y][x]==0) {
			FORR(a,A[r]) if(win[r][(x+N-a)%N]==-1) {
				win[r][(x+N-a)%N]=1;
				Q.push(r*10000+(x+N-a)%N);
			}
		}
		else {
			FORR(a,A[r]) if(win[r][(x+N-a)%N]==-1) {
				if(--num[r][(x+N-a)%N]==0) {
					win[r][(x+N-a)%N]=0;
					Q.push(r*10000+(x+N-a)%N);
				}
			}
		}
		
	}
	
	FOR(j,2) {
		for(i=1;i<N;i++) {
			if(win[j][i]==0) _P("Lose");
			if(win[j][i]==1) _P("Win");
			if(win[j][i]==-1) _P("Loop");
			_P((i==N-1)?"\n":" ");
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}