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


int X[6],Y[6];
vector<int> Xs,Ys;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) {
		cin>>X[i]>>Y[i];
		X[i]*=2;
		Y[i]*=2;
		Xs.push_back(X[i]-1);
		Xs.push_back(X[i]+1);
		Ys.push_back(Y[i]-1);
		Ys.push_back(Y[i]+1);
	}
	
	FORR(x,Xs) FORR(y,Ys) {
		int ok=0;
		if(x>X[0]&&x<X[1]&&y>Y[0]&&y<Y[1]) ok=1;
		if(x>X[2]&&x<X[3]&&y>Y[2]&&y<Y[3]) ok=0;
		if(x>X[4]&&x<X[5]&&y>Y[4]&&y<Y[5]) ok=0;
		if(ok) {
			cout<<"YES"<<endl;
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