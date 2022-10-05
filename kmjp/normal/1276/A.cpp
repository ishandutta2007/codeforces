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

int T;
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		set<int> R;
		FOR(i,N) {
			if(i+5<=N && S.substr(i,5)=="twone") {
				R.insert(i+2);
			}
		}
		vector<pair<int,char>> V;
		FOR(i,N) {
			if(R.count(i)==0) V.push_back({i,S[i]});
		}
		FOR(i,V.size()-1) if(i) {
			if(V[i-1].second=='t' && V[i].second=='w' && V[i+1].second=='o') {
				R.insert(V[i].first);
			}
			if(V[i-1].second=='o' && V[i].second=='n' && V[i+1].second=='e') {
				R.insert(V[i].first);
			}
		}
		cout<<R.size()<<endl;
		FORR(r,R) cout<<r+1<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}