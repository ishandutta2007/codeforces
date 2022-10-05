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
int A[101010],B[101010];
set<pair<int,int>> SA,SB;

vector<int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		SA.insert({A[i],i});
	}
	FOR(i,N) {
		cin>>B[i];
		SB.insert({B[i],i});
	}
	
	x = SA.rbegin()->second;
	C.push_back(x+1);
	SA.erase({A[x],x});
	SB.erase({B[x],x});
	FOR(i,(N-1)/2) {
		y = SB.begin()->second;
		SA.erase({A[y],y});
		SB.erase({B[y],y});
		x = SA.rbegin()->second;
		C.push_back(x+1);
		SA.erase({A[x],x});
		SB.erase({B[x],x});
	}
	FORR(r,SA) C.push_back(r.second+1);
	sort(ALL(C));
	cout<<C.size()<<endl;
	FORR(r,C) cout<<r<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}