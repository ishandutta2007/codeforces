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

int N,X,Y;
int R1,R2;
//#define DEB

int ask(vector<int> V) {
	cout<<"? ";
	cout<<V.size();
	FORR(c,V) cout<<" "<<c+1;
	cout<<endl;
	fflush(stdout);
	int ret=0;
#ifdef DEB
	FORR(c,V) {
		if(c+1==R1 || c+1==R2) ret^=Y;
		else ret^=X;
	}
#else
	cin>>ret;
#endif
	return ret;
}

int answer(int a,int b) {
	cout<<"! "<<a+1<<" "<<b+1<<endl;
	//exit(0);
}

bitset<1024> cand[10][2];
int ret[10][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
#ifdef DEB
	cin>>R1>>R2;
#endif
	
	int diff=0,high=0;
	FOR(i,10) {
		vector<int> A;
		FOR(x,N) if(x&(1<<i)) A.push_back(x);
		if(A.empty()) continue;
		x = ask(A);
		if(x==(X^Y) || x==Y) diff |= 1<<i, high=i;
	}
	
	int dif2=0;
	FOR(i,10) if(i!=high) {
		vector<int> A;
		FOR(x,N) if((x&(1<<i))&&((x&(1<<high))==0)) A.push_back(x);
		if(A.empty()) continue;
		x = ask(A);
		if(x==(X^Y) || x==Y) dif2 |= 1<<i;
	}
	
	answer(dif2,diff^dif2);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}