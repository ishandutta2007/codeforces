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
int P[1010101];
ll dif[1010101];
ll sum[1010101];
ll V[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&P[i]), P[i]--;
		//if(i!=j) continue;
		
		V[0]+=abs(P[i]-i);
		
		if(P[i]==i) {
			dif[0]++;
			sum[N-i]-=N-P[i];
			sum[N-i]+=P[i];
			dif[N-i+1]--;
			dif[N-i+1]--;
		}
		else if(P[i]>i) {
			dif[0]--;
			dif[P[i]-i+1]++;
			dif[P[i]-i+1]++;
			sum[N-i]-=N-P[i];
			sum[N-i]+=P[i];
			dif[N-i+1]--;
			dif[N-i+1]--;
		}
		else {
			dif[0]++;
			dif[N-i+1]--;
			dif[N-i+1]--;
			sum[N-i]-=N-P[i];
			sum[N-i]+=P[i];
			dif[N+P[i]-i+1]++;
			dif[N+P[i]-i+1]++;
		}
	}
	
	ll shi=0,ret=V[0];
	for(i=1;i<N;i++) {
		dif[i]+=dif[i-1];
		V[i]+=V[i-1]+dif[i]+sum[i];
		if(V[i]<ret) shi=i, ret=V[i];
	}
	//FOR(i,N) cout<<V[i]<<endl;
	
	cout<<ret<<" "<<shi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}