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

int N,M;
int SR[51],SC[51];
int TR[51],TC[51];
int X[51][51],Y[51][51];
vector<vector<int>> ret;
void move(int v,int dr,int dc) {
	int r=SR[v];
	int c=SC[v];
	
	ret.push_back({r,c,r+dr,c+dc});
	assert(X[r][c]==v);
	assert(X[r+dr][c+dc]==0);
	swap(X[r][c],X[r+dr][c+dc]);
	SR[v]+=dr;
	SC[v]+=dc;
}
void deb() {
	int x,y;
	FOR(y,N) {
		FOR(x,N) cout<<X[y+1][x+1];
		cout<<"  ";
		FOR(x,N) cout<<Y[y+1][x+1];
		cout<<endl;
	}
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(N==1) {
		_P("0\n");
		return;
	}
	
	FOR(i,M) {
		cin>>SR[i+1]>>SC[i+1];
		X[SR[i+1]][SC[i+1]]=i+1;
	}
	FOR(i,M) {
		cin>>TR[i+1]>>TC[i+1];
		Y[TR[i+1]][TC[i+1]]=i+1;
	}
	
	for(x=1;x<=N;x++) if(X[1][x]) {
		j=X[1][x];
		while(SC[j]>1 && X[1][SC[j]-1]==0) move(j,0,-1);
	}
	for(y=2;y<=N;y++) for(x=N;x>=1;x--) if(X[y][x]) {
		j=X[y][x];
		while(SR[j]>1) {
			if(X[SR[j]-1][SC[j]]==0) move(j,-1,0);
			else move(j,0,1);
		}
		while(SC[j]>1 && X[1][SC[j]-1]==0) move(j,0,-1);
	}
	for(y=N;y>=3;y--) {
		for(x=1;x<=N;x++) if(X[1][x]) {
			j=X[1][x];
			if(TR[j]!=y) continue;
			move(j,1,0);
			while(SC[j]<TC[j]) move(j,0,1);
			while(SC[j]>TC[j]) move(j,0,-1);
			while(SR[j]<TR[j]) move(j,1,0);
		}
	}
	vector<int> cand;
	for(x=N;x>=1;x--) if(Y[2][x]) cand.push_back(Y[2][x]);
	for(x=1;x<=N;x++) if(Y[1][x]) cand.push_back(Y[1][x]);
	
	FORR(c,cand) {
		// right?
		for(x=SC[c]+1;x<=N;x++) if(X[1][x]) break;
		if(x>N) continue;
		move(c,1,0);
		while(SC[c]<N) move(c,0,1);
		for(x=N;x>=1;x--) if(X[1][x]==0) break;
		while(x<N) {
			move(X[1][x+1],0,-1);
			x++;
		}
		move(c,-1,0);
	}
	FORR(c,cand) {
		if(TR[c]==2) {
			while(SC[c]>1) move(c,0,-1);
			move(c,1,0);
			while(SC[c]<TC[c]) move(c,0,1);
		}
		else {
			while(SC[c]>1 && X[1][SC[c]-1]==0) move(c,0,-1);
		}
	}
	reverse(ALL(cand));
	FORR(c,cand) if(TR[c]==1) {
		while(SC[c]<TC[c]) move(c,0,1);
	}
	
	
	cout<<ret.size()<<endl;
	FORR(c,ret) cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
	
	
	for(i=1;i<=M;i++) assert(SR[i]==TR[i] && SC[i]==TC[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}