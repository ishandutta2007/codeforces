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

int N;
ll V[5050],D[5050],P[5050];
int is[4040];
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i]>>D[i]>>P[i],is[i]=1;
	
	FOR(i,N) if(is[i]) {
		R.push_back(i);
		for(j=i+1;j<N;j++) {
			if(is[j] && V[i]>0) P[j]-=V[i]--;
		}
		ll r=0;
		for(j=i+1;j<N;j++) {
			P[j]-=r;
			if(is[j]&&P[j]<0) {
				is[j]=0;
				r+=D[j];
			}
		}
	}
	
	_P("%d\n",R.size());
	FORR(r,R) _P("%d ",r+1);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}