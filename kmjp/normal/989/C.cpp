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

int A,B,C,D;
string S[50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	FOR(y,50) {
		S[y]=string(50,'.');
		FOR(x,50) {
			if(y==0) S[y][x]='A';
			else if(y>0 && y<24) S[y][x]='A'+(x&1);
			if(y==24) S[y][x]='B';
			if(y==25) S[y][x]='C';
			else if(y>25 && y<49) S[y][x]='C'+(x&1);
			if(y==49) S[y][x]='D';
		}
	}
	
	// A
	for(x=0;x<50;x+=2) for(y=1;y<=22;y+=2) if(A>1) S[y][x]='B', A--;
	for(x=49;x>1;x-=2) for(y=2;y<=22;y+=2) if(B>1) S[y][x]='A', B--;
	for(x=0;x<50;x+=2) for(y=26;y<=47;y+=2) if(C>1) S[y][x]='D', C--;
	for(x=49;x>1;x-=2) for(y=27;y<=47;y+=2) if(D>1) S[y][x]='C', D--;
	
	cout<<"50 50"<<endl;
	FOR(y,50) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}