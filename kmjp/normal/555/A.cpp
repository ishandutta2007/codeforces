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

int N,K;
int M[101010];
vector<int> A[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K;
	
	int ret=0,sp=K;
	FOR(i,K) {
		cin>>M[i];
		FOR(j,M[i]) cin>>x, A[i].push_back(x);
		if(A[i][0]==1) {
			FOR(j,M[i]-1) if(A[i][j]+1!=A[i][j+1]) {
				ret += M[i]-1-j;
				sp += M[i]-1-j;
				break;
			}
		}
		else {
			ret += M[i]-1;
			sp += M[i]-1;
		}
	}
	
	cout<<ret+(sp-1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}