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
string S[101010];
char buf[1010101];
int L;
string R;
vector<int> add[2010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%s%d",buf,&x);
		S[i]=buf;
		while(x--) {
			scanf("%d",&y);
			add[y-1].push_back(i);
			L=max(L,y+(int)S[i].size()-1);
		}
	}
	R.resize(L,'a');
	deque<pair<int,int>> Q;
	FOR(i,L) {
		while(Q.size() && Q.front().second<i) Q.pop_front();
		FORR(e,add[i]) {
			int x=i+S[e].size()-1;
			while(Q.size() && Q.back().second<=x) Q.pop_back();
			Q.push_back({e,x});
		}
		
		if(Q.size()) {
			x=Q.front().first;
			y=Q.front().second;
			R[i]=S[x][S[x].size()-1-(y-i)];
		}
		
	}
	cout<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}