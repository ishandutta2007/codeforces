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
int X[202020];

int mi() {
	int pre=-10;
	int i,num=0;
	
	FOR(i,N) {
		if(abs(pre-X[i])>1) {
			pre=X[i]+1;
			num++;
		}
	}
	return num;
}

int ma() {
	int pre=-10;
	int i,num=0;
	
	FOR(i,N) {
		if(pre<X[i]-1) {
			pre=X[i]-1;
			num++;
		}
		else if(pre==X[i]-1) {
			pre=X[i];
			num++;
		}
		else if(pre==X[i]) {
			pre=X[i]+1;
			num++;
		} 
	}
	return num;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	sort(X,X+N);
	
	cout<<mi()<<" "<<ma()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}