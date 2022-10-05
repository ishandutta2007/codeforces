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

int N,K;
int X[202020],Y[202020];
set<pair<int,int> > SX,SY;
vector<int> rem;

void del(int x) {
	rem.push_back(x);
	SY.erase({Y[x],x});
	SX.erase({X[x],x});
}

void solve() {
	int i,j,k,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		X[i]=(x1+x2);
		Y[i]=(y1+y2);
		SX.insert({X[i],i});
		SY.insert({Y[i],i});
	}
	
	ll mi=1LL<<61;
	int l,r,t,b;
	for(l=0;l<=K;l++) for(r=0;l+r<=K;r++) for(t=0;l+r+t<=K;t++) {
		b=K-l-r-t;
		rem.clear();
		FOR(i,l) del(SX.begin()->second);
		FOR(i,r) del(SX.rbegin()->second);
		FOR(i,t) del(SY.begin()->second);
		FOR(i,b) del(SY.rbegin()->second);
		
		ll w = SX.rbegin()->first-SX.begin()->first;
		w = (w+1)/2;
		if(w<=0) w=1;
		ll h = SY.rbegin()->first-SY.begin()->first;
		h = (h+1)/2;
		if(h<=0) h=1;
		
		mi =min(mi,w*h);
		
		FORR(r,rem) {
			SX.insert({X[r],r});
			SY.insert({Y[r],r});
		}
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}