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

int N,M;
set<int> S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		S[x-1].insert(y-1);
		S[y-1].insert(x-1);
	}
	queue<int> L;
	FOR(i,N) L.push(i);
	
	int num=0;
	while(L.size()) {
		x=L.front();
		L.pop();
		num++;
		queue<int> Q;
		Q.push(x);
		
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			queue<int> L2;
			while(L.size()) {
				r=L.front();
				L.pop();
				if(S[x].count(r)) {
					L2.push(r);
				}
				else {
					Q.push(r);
				}
			}
			swap(L,L2);
		}
	}
	cout<<num-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}