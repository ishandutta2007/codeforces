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

int N;
pair<int,int> P[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	vector<int> V[2];
	FOR(i,N) V[P[i].first<0].push_back(P[i].second);
	reverse(ALL(V[1]));
	
	if(V[0].size()<=V[1].size()) {
		x=V[0].size();
		y=min(V[0].size()+1,V[1].size());
	}
	else {
		x=min(V[1].size()+1,V[0].size());
		y=V[1].size();
	}
	int tot=0;
	FOR(i,x) tot+=V[0][i];
	FOR(i,y) tot+=V[1][i];
	cout<<tot<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}