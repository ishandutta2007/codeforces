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

int H,W,T;
vector<bitset<1024>> B;
string S[1010];
int Y,X;
ll P;

ll step[1010][1010];
/*
vector<bitset<1024>> step(vector<bitset<1024>> S) {
	vector<bitset<1024>> R=S;
	
	int y,x;
	FOR(y,H) FOR(x,W) {
		int is=0;
		if(y&&S[y-1][x]==S[y][x]) is++;
		if(y+1<H&&S[y+1][x]==S[y][x]) is++;
		if(x&&S[y][x-1]==S[y][x]) is++;
		if(x+1<W&&S[y][x+1]==S[y][x]) is++;
		if(is) R[y][x]=R[y][x]^1;
	}
	return R;
}


*/

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T;
	B.resize(H);
	FOR(y,H) {
		cin>>s;
		FOR(x,W) {
			if(s[x]=='1') B[y][x]=1;
			step[y][x]=1LL<<60;
		}
	}
	queue<int> Q;
	FOR(y,H) FOR(x,W) {
		int is=0;
		if(y&&B[y-1][x]==B[y][x]) is++;
		if(y+1<H&&B[y+1][x]==B[y][x]) is++;
		if(x&&B[y][x-1]==B[y][x]) is++;
		if(x+1<W&&B[y][x+1]==B[y][x]) is++;
		if(is) step[y][x]=0, Q.push(y*1000+x);
	}
	
	while(Q.size()) {
		y=Q.front()/1000;
		x=Q.front()%1000;
		Q.pop();
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=y+dd[i];
			int tx=x+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(step[ty][tx]<=step[y][x]+1) continue;
			step[ty][tx]=step[y][x]+1;
			Q.push(ty*1000+tx);
			
		}
	}
	
	
	FOR(i,T) {
		cin>>Y>>X>>P;
		Y--;
		X--;
		if(P<=step[Y][X]) {
			cout<<B[Y][X]<<endl;
		}
		else {
			cout<<(B[Y][X]^((P-step[Y][X])%2))<<endl;
		}
		
	}
	
	/*
	FOR(i,10) {
		cout<<i<<endl;
		FOR(y,H) {
			FOR(x,W) cout<<B[y][x];
			cout<<endl;
		}
		B=step(B);
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}