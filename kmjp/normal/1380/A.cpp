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
int P[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> S;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>P[i];
			S.insert(i);
			V.push_back({P[i],i});
		}
		sort(ALL(V));
		reverse(ALL(V));
		int ok=0;
		FORR(v,V) {
			auto it=S.find(v.second);
			if(it!=S.begin() && next(it)!=S.end()) {
				ok=1;
				cout<<"YES"<<endl;
				cout<<(*prev(it)+1)<<" "<<(*it+1)<<" "<<(*next(it)+1)<<endl;
				break;
			}
			S.erase(it);
		}
		if(ok==0) cout<<"NO"<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}