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

int A,B,C;
int M;
vector<int> V[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	cin>>M;
	FOR(i,M) {
		cin>>x>>s;
		V[s[0]=='P'].push_back(x);
	}
	FOR(i,2) sort(ALL(V[i])), reverse(ALL(V[i]));
	
	int num=0;
	ll cost=0;
	FOR(i,A) if(V[0].size()) {
		num++;
		cost+=V[0].back();
		V[0].pop_back();
	}
	FOR(i,B) if(V[1].size()) {
		num++;
		cost+=V[1].back();
		V[1].pop_back();
	}
	FORR(r,V[1]) V[0].push_back(r);
	sort(ALL(V[0])), reverse(ALL(V[0]));
	
	FOR(i,C) if(V[0].size()) {
		num++;
		cost+=V[0].back();
		V[0].pop_back();
	}
	
	cout<<num<<" "<<cost<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}