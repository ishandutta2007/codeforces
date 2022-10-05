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

int T;
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--){
		cin>>N;
		
		if(N%4==0) {
			deque<int> D;
			x=0;
			FOR(i,N/4) {
				D.push_back(x+1);
				D.push_back(x+5);
				D.push_front(x+2);
				D.push_front(x+4);
				x+=6;
			}
			cout<<"YES"<<endl;
			FORR(d,D) cout<<d<<" ";
			cout<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}