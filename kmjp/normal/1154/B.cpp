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
int A[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> A;
	FOR(i,N) {
		cin>>x;
		A.push_back(x);
	}
	sort(ALL(A));
	A.erase(unique(ALL(A)),A.end());
	
	if(A.size()==1) {
		cout<<0<<endl;
	}
	else if(A.size()==2) {
		if((A[1]-A[0])%2==0) {
			cout<<(A[1]-A[0])/2<<endl;
		}
		else {
			cout<<(A[1]-A[0])<<endl;
		}
	}
	else if(A.size()==3 && (A[1]-A[0])==A[2]-A[1]) {
		cout<<(A[1]-A[0])<<endl;
	}
	else {
		cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}