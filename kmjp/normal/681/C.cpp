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

string S[3]={"insert","getMin","removeMin"};
int N;
int T[101010],A[101010];
vector<pair<int,int>> V;
multiset<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FOR(x,3) if(s==S[x]) break;
		
		if(x==0) {
			cin>>x;
			V.push_back({0,x});
			M.insert(x);
		}
		else if(x==1) {
			cin>>x;
			
			while(M.size() && *M.begin()<x) {
				V.push_back({2,0});
				M.erase(M.begin());
			}
			if(M.empty() || *M.begin()>x) {
				V.push_back({0,x});
				M.insert(x);
			}
			
			assert(*M.begin()==x);
			V.push_back({1,x});
		}
		else if(x==2) {
			if(M.empty()) {
				V.push_back({0,0});
				M.insert(0);
			}
			V.push_back({2,0});
			M.erase(M.begin());
		}
	}
	
	_P("%d\n",V.size());
	FORR(r,V) {
		if(r.first<2) _P("%s %d\n",S[r.first].c_str(),r.second);
		else _P("%s\n",S[r.first].c_str());
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}