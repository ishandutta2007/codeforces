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
int N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		string T;
		vector<pair<int,int>> R;
		K--;
		FOR(i,N/2-K) {
			T+='(';
		}
		FOR(i,N/2-K) {
			T+=')';
		}
		while(T.size()<N) T+="()";
		for(i=N-1;i>=0;i--) {
			if(S[i]!=T[i]){
				for(x=i-1;x>=0;x--) {
					if(S[x]!=S[i]) {
						R.push_back({x,i});
						for(y=x,r=i;y<r;y++,r--) swap(S[y],S[r]);
						break;
					}
				}
			}
		}
		//cout<<S<<endl;
		//cout<<T<<endl;
		cout<<R.size()<<endl;
		FORR(r,R) cout<<(r.first+1)<<" "<<(r.second+1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}