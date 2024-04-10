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

int N,X,Y;
int nseg[45];
ll from[1<<22];
ll to[1<<22];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	int mask;

	int P=X+Y;
	int rep=N/P,lef=N%P;
	FOR(i,P) {
		if(i<lef) nseg[i]=rep+1;
		else nseg[i]=rep;
	}
	
	FOR(mask,1<<22) from[mask]=-1<<28;
	from[0]=0;
	
	FOR(i,P) {
		FOR(mask,1<<22) to[mask]=-1<<28;
		FOR(mask,1<<22) {
			int nmask=(mask<<1)&((1<<22)-1);
			chmax(to[nmask],from[mask]);
			if((mask&(1<<(X-1))) || (mask&(1<<(Y-1)))) continue;
			chmax(to[nmask|1],from[mask]+nseg[i]);
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(mask,1<<22) ret=max(ret,from[mask]);
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}