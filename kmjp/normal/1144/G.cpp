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
int A[202020];

int LIS[202020];
int LDS[202020];
int from[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(from);
	
	FOR(i,N) {
		cin>>A[i];
		if(i==0) {
			LIS[i]=200001;
			LDS[i]=-1;
			from[i][0]=from[i][1]=0;
		}
		else {
			LIS[i]=-1;
			LDS[i]=200001;
			if(from[i-1][0]>=0) {
				// {A[i-1],LIS[i-1]}
				if(A[i]>A[i-1]) {
					LIS[i]=LIS[i-1];
					from[i][0]=0;
				}
				if(A[i]<LIS[i-1]) {
					LDS[i]=A[i-1];
					from[i][1]=0;
				}
			}
			if(from[i-1][1]>=0) {
				// {LDS[i-1],A[i-1]};
				if(A[i]>LDS[i-1] && A[i-1]>LIS[i]) {
					LIS[i]=A[i-1];
					from[i][0]=1;
				}
				if(A[i]<A[i-1] && LDS[i-1]<LDS[i]) {
					LDS[i]=LDS[i-1];
					from[i][1]=1;
				}
			}
		}
	}
	
	FOR(i,2) {
		if(from[N-1][i]>=0) {
			cout<<"YES"<<endl;
			
			vector<int> V;
			int cur=i;
			for(j=N-1;j>=0;j--) {
				V.push_back(cur);
				cur=from[j][cur];
			}
			
			
			reverse(ALL(V));
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}