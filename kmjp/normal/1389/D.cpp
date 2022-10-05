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
ll N;
ll K;
int L[3],R[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		cin>>L[0]>>R[0];
		cin>>L[1]>>R[1];
		L[2]=max(L[0],L[1]);
		R[2]=min(R[0],R[1]);
		ll C=R[2]-L[2];
		
		ll dif,len;
		if(C>=0) {
			K-=1LL*C*N;
			dif=0;
			len=max({R[0]-L[1],R[1]-L[0],R[1]-L[1],R[0]-L[0]})-C;
		}
		else {
			dif=abs(C);
			len=max({R[0]-L[1],R[1]-L[0],R[1]-L[1],R[0]-L[0]});
		}
		
		ll ret=1LL<<60;
		if(K<=0) {
			ret=0;
		}
		else {
			for(i=1;i<=N;i++) {
				ll cost=i*dif;
				if(K<=len*i) {
					cost+=K;
				}
				else {
					cost+=len*i+(K-len*i)*2;
				}
				ret=min(ret,cost);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}