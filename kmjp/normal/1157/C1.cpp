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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	int L=1,R=N;
	int pre=0;
	
	string S;
	while(S.size()<N) {
		if(L==R) {
			if(A[L]>pre) {
				S.push_back('L');
			}
			break;
		}
		if(A[L]<A[R]) {
			if(A[L]>pre) {
				S.push_back('L');
				pre=A[L++];
			}
			else if(A[R]>pre) {
				S.push_back('R');
				pre=A[R--];
			}
			else {
				break;
			}
		}
		else if(A[L]>A[R]) {
			if(A[R]>pre) {
				S.push_back('R');
				pre=A[R--];
			}
			else if(A[L]>pre) {
				S.push_back('L');
				pre=A[L++];
			}
			else {
				break;
			}
		}
		else {
			if(A[L]<=pre) break;
			for(x=L+1;x<=R;x++) if(A[x]<=A[x-1]) break;
			for(y=R-1;y>=L;y--) if(A[y]<=A[y+1]) break;
			if(x-L>R-y) {
				S.push_back('L');
				pre=A[L++];
			}
			else {
				S.push_back('R');
				pre=A[R--];
			}
		}
		
	}
	cout<<S.size()<<endl;
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}