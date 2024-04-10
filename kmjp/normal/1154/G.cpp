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

int N;
int C[10101011];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(C);
	ll mi=1LL<<60;
	int L=-1,R=-1;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(C[x]>=0) {
			if(x<mi) {
				mi=x;
				L=i;
				R=C[x];
			}
		}
		else {
			C[x]=i;
		}
	}
	
	for(i=1;i<=10000000;i++) {
		int id=-1;
		ll v=-1;
		for(j=i;j<=10000000;j+=i) {
			if(C[j]>=0) {
				if(v>=0) {
					ll cand=v/i*j;
					if(cand<mi) {
						mi=cand;
						L=id;
						R=C[j];
					}
					break;
				}
				id=C[j];
				v=j;
			}
		}
	}
	if(L>R) swap(L,R);
	cout<<L+1<<" "<<R+1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}