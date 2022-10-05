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

int N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==2 && N>4) {
		cout<<N-1<<endl;
		FOR(i,N-1) {
			cout<<(i+1)<<" "<<(i+2)<<endl;
		}
	}
	else if(K==3 && N>=4) {
		cout<<N-1<<endl;
		cout<<"1 2"<<endl;
		cout<<"2 3"<<endl;
		cout<<"3 4"<<endl;
		for(i=5;i<=N;i++) cout<<"2 "<<i<<endl;
	}
	else {
		cout<<-1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}