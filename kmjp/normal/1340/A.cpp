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
int P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		multiset<int> ma;
		FOR(i,N) {
			cin>>x;
			P[x-1]=i;
			M[i]=1;
			ma.insert(1);
		}
		
		FOR(i,N) {
			x=*ma.rbegin();
			if(M[P[i]]!=x) break;
			ma.erase(ma.find(x));
			M.erase(P[i]);
			auto it=M.lower_bound(P[i]);
			if(it!=M.end()) {
				ma.erase(ma.find(it->second));
				it->second+=x;
				ma.insert(it->second);
			}
		}
		if(i==N) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}