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

int H;
int A[202020];
int P[201010];
int S[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H;
	int p=0;
	int cur=1;
	FOR(i,H+1) {
		S[i]=cur;
		cin>>A[i];
		FOR(j,A[i]) P[cur++]=p;
		p=cur-1;
	}
	FOR(i,H) if(A[i]>1 && A[i+1]>1) {
		cout<<"ambiguous"<<endl;
		for(j=1;j<cur;j++) {
			if(j>1) cout<<" ";
			cout<<P[j];
		}
		cout<<endl;
		P[S[i+1]]--;
		for(j=1;j<cur;j++) {
			if(j>1) cout<<" ";
			cout<<P[j];
		}
		cout<<endl;
		return;
	}
	cout<<"perfect"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}