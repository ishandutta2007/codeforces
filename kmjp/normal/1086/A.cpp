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

int X[3],Y[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	FOR(i,3) FOR(j,2) {
		if(X[j]>X[j+1]) swap(X[j],X[j+1]),swap(Y[j],Y[j+1]);
	}
	
	set<pair<int,int>> S;
	
	if(Y[1]>max(Y[0],Y[2])) {
		for(x=X[0];x<=X[2];x++) S.insert({x,max(Y[0],Y[2])});
		for(y=Y[0];y<=max(Y[0],Y[2]);y++) S.insert({X[0],y});
		for(y=Y[2];y<=max(Y[0],Y[2]);y++) S.insert({X[2],y});
		for(y=max(Y[0],Y[2]);y<=Y[1];y++) S.insert({X[1],y});
	}
	else if(Y[1]<min(Y[0],Y[2])) {
		for(x=X[0];x<=X[2];x++) S.insert({x,min(Y[0],Y[2])});
		for(y=Y[0];y>=min(Y[0],Y[2]);y--) S.insert({X[0],y});
		for(y=Y[2];y>=min(Y[0],Y[2]);y--) S.insert({X[2],y});
		for(y=min(Y[0],Y[2]);y>=Y[1];y--) S.insert({X[1],y});
	}
	else {
		for(x=X[0];x<=X[1];x++) S.insert({x,Y[0]});
		for(y=min(Y[0],Y[2]);y<=max(Y[0],Y[2]);y++) S.insert({X[1],y});
		for(x=X[1];x<=X[2];x++) S.insert({x,Y[2]});
	}
	
	cout<<S.size()<<endl;
	FORR(s,S) cout<<s.first<<" "<<s.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}