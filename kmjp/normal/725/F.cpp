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
int A1,B1,A2,B2;
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	priority_queue<int> Q;
	FOR(i,N) {
		cin>>A1>>B1>>A2>>B2;
		if(A1<=B2 && B1<=A2) continue;
		if(A1+B1<=A2+B2) {
			if(A1-B2>=0) ret +=A1-B2;
			else ret +=A2-B1;
		}
		else {
			ret += A1+A2;
			Q.push(A1+B1);
			Q.push(A2+B2);
		}
	}
	for(i=0;Q.size();i^=1,Q.pop()) ret -= i*Q.top();
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}