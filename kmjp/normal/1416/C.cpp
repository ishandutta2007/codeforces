#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[303030];
pair<int,int> P[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[i]={0,i};
	}
	
	int up=1<<30;
	ll ret=0;
	ll in=0;
	for(j=29;j>=0;j--) {
		ll C[2]={};
		ll I[2]={};
		FOR(i,N) {
			x=P[i].second;
			if(i&&(P[i].first)!=(P[i-1].first)) {
				C[0]=C[1]=0;
			}
			if(A[x]&(1<<j)) {
				I[1]+=C[0];
				C[1]++;
			}
			else {
				I[0]+=C[1];
				C[0]++;
			}
		}
		if(I[0]<=I[1]) {
			in+=I[0];
		}
		else {
			in+=I[1];
			ret+=1<<j;
		}
		up|=1<<j;
		FOR(i,N) P[i]={A[i]&up,i};
		sort(P,P+N);
		
	}
	cout<<in<<" "<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}