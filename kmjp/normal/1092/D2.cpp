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

vector<pair<int,int>> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(S.empty() || x<S.back().first) {
			S.push_back({x,1});
		}
		else if(x==S.back().first) {
			S.back().second++;
			while(S.size()>1 && S.back().second%2==0) {
				S.pop_back();
				S.back().second+=2;
			}
		}
		else if(x>S.back().first) {
			FORR(v,S) if(v.second%2) return _P("NO\n");
			S.clear();
			S.push_back({x,1});
		}
	}
	
	if(S.size()>1) return _P("NO\n");
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}