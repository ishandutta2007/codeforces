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
map<string,vector<string>> S;

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		cin>>x;
		FOR(j,x) {
			cin>>t;
			S[s].push_back(t);
		}
	}
	
	cout<<S.size()<<endl;
	FORR(e,S) {
		vector<string> V=e.second,W;
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		reverse(ALL(V));
		
		FORR(v,V) {
			int ng=0;
			FORR(w,V) if(w.size()>v.size() && w.substr(w.size()-v.size())==v) ng=1;
			if(ng==0) W.push_back(v);
		}
		cout<<e.first<<" "<<W.size();
		FORR(w,W) cout<<" "<<w;
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}