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
int A[2020];

int L1[2020],R2[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		L1[i]=L1[i-1]+(A[i]==1);
	}
	for(i=N;i>=1;i--) {
		R2[i]=R2[i+1]+(A[i]==2);
	}
	
	int ma=max(L1[N],R2[1]);
	
	for(x=N;x>=1;x--) {
		int B[3]={};
		for(y=x;y>=1;y--) {
			if(A[y]==1) {
				B[1]++;
				B[2]=max(B[1],B[2]);
			}
			else {
				B[2]++;
			}
			ma=max({ma,B[2]+R2[x+1]+L1[y-1]});
		}
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}