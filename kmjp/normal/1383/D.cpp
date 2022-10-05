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


int H,W;
int A[303][303];
int B[303][303];
int R[303],C[303];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) {
			cin>>r;
			R[y]=max(R[y],r);
			C[x]=max(C[x],r);
		}
	}
	
	int CH=0,CW=0;
	queue<pair<int,int>> Q;
	for(i=H*W;i>=1;i--) {
		int inR=count(R,R+H,i);
		int inC=count(C,C+W,i);
		if(inR) CH++;
		if(inC) CW++;
		if(inR||inC) {
			B[CH-1][CW-1]=i;
		}
		else {
			y=Q.front().first;
			x=Q.front().second;
			B[y][x]=i;
			Q.pop();
		}
		
		if(inR) {
			for(x=CW-2;x>=0;x--) Q.push({CH-1,x});
		}
		if(inC) {
			for(y=CH-2;y>=0;y--) Q.push({y,CW-1});
		}
	}
	
	FOR(y,H) {
		FOR(x,W) cout<<B[y][x]<<" ";
		cout<<endl;
	}
		
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}