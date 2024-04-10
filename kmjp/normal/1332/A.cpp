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
int A,B,C,D;
int X1,X2,X3,Y1,Y2,Y3;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D;
		cin>>x>>y>>X1>>Y1>>X2>>Y2;
		X1-=x,X2-=x;
		Y1-=y,Y2-=y;
		if(Y1>0 || Y2<0 || X1>0 || X2<0) {
			cout<<"No"<<endl;
			continue;
		}
		
		if(X1>B-A||B-A>X2) {
			cout<<"No"<<endl;
			continue;
		}
		if(X1==0 && X2==0 && (A||B)) {
			cout<<"No"<<endl;
			continue;
		}
		if(Y1>D-C||D-C>Y2) {
			cout<<"No"<<endl;
			continue;
		}
		if(Y1==0 && Y2==0 && (C||D)) {
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}