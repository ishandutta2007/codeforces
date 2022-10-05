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
string S,T;
vector<int> D[4];
vector<int> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	FOR(i,N) {
		x=(S[i]-'0')+(T[i]-'0')*2;
		D[x].push_back(i);
	}
	
	FOR(i,D[1].size()+1) FOR(j,D[2].size()+1) {
		if(i+j>N/2) continue;
		x=i;
		y=D[2].size()-j;
		if(D[3].size()<abs(x-y)) continue;
		if((D[3].size()-abs(x-y))%2) continue;
		int z=(D[3].size()-abs(x-y))/2;
		if(y>x) z+=y-x;
		if(x+j+z+D[0].size()<N/2) continue;
		if(x+j+z>N/2) continue;
		if(x+z!=y+D[3].size()-z) continue;
		FOR(i,x) A.push_back(D[1][i]);
		FOR(i,j) A.push_back(D[2][i]);
		FOR(i,z) A.push_back(D[3][i]);
		FOR(i,D[0].size()) {
			if(A.size()>=N/2) break;
			A.push_back(D[0][i]);
		}
		
		sort(ALL(A));
		FORR(a,A) cout<<a+1<<" ";
		return;
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}