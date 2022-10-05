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
int A[202020];
int S[202][202020];
vector<int> C[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,202) C[i].clear();
		FOR(i,N) {
			cin>>x;
			x--;
			C[x].push_back(i);
			FOR(j,202) S[j][i+1]=S[j][i];
			S[x][i+1]++;
		}
		
		int ma=0;
		FOR(i,200) {
			ma=max(ma,(int)C[i].size());
			
			for(j=0,k=C[i].size()-1;j<k;j++,k--) {
				FOR(x,200) if(i!=x) ma=max(ma,2*(j+1)+S[x][C[i][k]]-S[x][C[i][j]]);
			}
		}
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}