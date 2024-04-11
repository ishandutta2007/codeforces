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

int M;
ll H[2],A[2];
ll X[2],Y[2];
ll fir[2],sec[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,2) cin>>H[i]>>A[i]>>X[i]>>Y[i];
	FOR(i,2) {
		fir[i]=sec[i]=-1;
		FOR(j,2000100) {
			H[i]=(X[i]*H[i]+Y[i])%M;
			
			if(H[i]==A[i]) {
				if(fir[i]==-1) fir[i]=j+1;
				else {
					sec[i]=j+1;
					break;
				}
			}
		}
	}
	if(fir[0]==-1 || fir[1]==-1) return _P("-1\n");
	
	ll per=(sec[0]==-1)?0:(sec[0]-fir[0]);
	ll per2=(sec[1]==-1)?0:(sec[1]-fir[1]);
	
	FOR(i,2000100) {
		ll tim=fir[0]+per*i;
		bool ok=false;
		if(per2==0) {
			ok=tim==fir[1];
		}
		else {
			ok=(tim>=fir[1] && (tim-fir[1])%per2==0);
		}
		if(ok) {
			cout<<tim<<endl;
			return;
		}
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}