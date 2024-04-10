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

int N,K;
int H[202020];
const ll mo=998244353;

ll from[4020];
ll to[4020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>H[i];
		H[i]--;
	}
	H[N]=H[0];
	
	from[2010]=1;
	FOR(i,N) {
		ZERO(to);
		FOR(y,4010) if(from[y]) {
			if(H[i]==H[i+1]) {
				to[y]=from[y]*K%mo;
			}
			else {
				// AC->WA
				(to[y-1]+=from[y])%=mo;
				// WA->AC
				(to[y+1]+=from[y])%=mo;
				(to[y]+=(K-2)*from[y])%=mo;
			}
		}
		
		
		swap(from,to);
	}
	
	ll ret=0;
	for(y=2011;y<=4010;y++) ret+=from[y];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}