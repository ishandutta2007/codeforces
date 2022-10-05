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

int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	if(K%2==0) {
		_P("NO\n");
	}
	else if(K==1) {
		_P("YES\n2 1\n1 2\n");
	}
	else {
		vector<pair<int,int> > P;
		
		P.push_back(make_pair(1,4));
		P.push_back(make_pair(2,3));
		P.push_back(make_pair(5,6));
		FOR(i,K-1) {
			P.emplace_back(1,7+i);
			P.emplace_back(2,7+i);
			P.emplace_back(3,7+i);
			P.emplace_back(4,7+i+K-1);
			P.emplace_back(5,7+i+K-1);
			P.emplace_back(6,7+i+K-1);
		}
		FOR(x,K-1) for(y=x+1;y<K-1;y++) {
			if((x^1)==y) continue;
			P.emplace_back(7+x,7+y),P.emplace_back(7+x+K-1,7+y+K-1);
		}
		
		_P("YES\n");
		_P("%d %d\n",6+2*(K-1),P.size());
		FORR(r,P) _P("%d %d\n",r.first,r.second);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}