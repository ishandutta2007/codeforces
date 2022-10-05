#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N;
int A[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> S;
		FOR(i,N) {
			cin>>A[i];
			S.insert(A[i]);
		}
		if(S.size()==1) {
			cout<<"NO"<<endl;
		}
		else {
			vector<pair<int,int>> R;
			x=-1;
			for(i=1;i<N;i++) if(A[i]!=A[0]) {
				x=i;
				R.push_back({0,i});
			}
			for(i=1;i<N;i++) if(A[i]==A[0]) {
				R.push_back({x,i});
			}
			cout<<"YES"<<endl;
			FORR(r,R) cout<<r.first+1<<" "<<r.second+1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}