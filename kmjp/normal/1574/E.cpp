#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int W,H,K;
const ll mo=998244353;

unordered_map<int,int> M[1303030];
int P[2];
int Rpat[3];
int Cpat[3];
int NR[1303030],NC[1303030];
int NRpat[1303030][2],NCpat[1303030][2];
ll p2[1303030];


void clear(int x,int y) {
	if(M[x].count(y)==0) return;
	int c=M[x][y];
	M[x].erase(y);
	
	P[(x^y^c)&1]--;
	
	Cpat[NC[x]]--;
	NCpat[x][(y^c)&1]--;
	NC[x]=2-(NCpat[x][0]>0)-(NCpat[x][1]>0);
	Cpat[NC[x]]++;

	Rpat[NR[y]]--;
	NRpat[y][(x^c)&1]--;
	NR[y]=2-(NRpat[y][0]>0)-(NRpat[y][1]>0);
	Rpat[NR[y]]++;
	
	
}

void add(int x,int y,int c) {
	M[x][y]=c;
	P[(x^y^c)&1]++;
	
	Cpat[NC[x]]--;
	NCpat[x][(y^c)&1]++;
	NC[x]=2-(NCpat[x][0]>0)-(NCpat[x][1]>0);
	Cpat[NC[x]]++;

	Rpat[NR[y]]--;
	NRpat[y][(x^c)&1]++;
	NR[y]=2-(NRpat[y][0]>0)-(NRpat[y][1]>0);
	Rpat[NR[y]]++;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&W,&H,&K);
	FOR(i,W) NC[i]=2, Cpat[2]++;
	FOR(i,H) NR[i]=2, Rpat[2]++;
	p2[0]=1;
	FOR(i,1302020) p2[i+1]=p2[i]*2%mo;
	
	while(K--) {
		scanf("%d%d%d",&x,&y,&k);
		x--,y--;
		clear(x,y);
		if(k>=0) add(x,y,k);
		
		ll ret=0;
		/*
		cout<<Cpat[0]<<Cpat[1]<<Cpat[2]<<endl;
		cout<<Rpat[0]<<Rpat[1]<<Rpat[2]<<endl;
		cout<<P[0]<<P[1]<<endl;
		*/
		if(Cpat[0]==0) ret+=p2[Cpat[2]];
		if(Rpat[0]==0) ret+=p2[Rpat[2]];
		if(P[0]==0) ret--;
		if(P[1]==0) ret--;
		cout<<(ret+mo)%mo<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}