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
int N,X,Y,Z;
ll A[303030];

int pat[6][6][6][3][1050];
int rep[6][6][6];

int grundy[2][2][1050];

int hoge(int cur,int p) {
	if(cur<=0) return pat[X][Y][Z][p][cur]=0;
	
	if(pat[X][Y][Z][p][cur]>=0) return pat[X][Y][Z][p][cur];
	set<int> S;
	S.insert(hoge(cur-X,0));
	if(p!=1) S.insert(hoge(cur-Y,1));
	if(p!=2) S.insert(hoge(cur-Z,2));
	int ret=0;
	while(S.count(ret)) ret++;
	
	return pat[X][Y][Z][p][cur]=ret;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pat);
	for(X=1;X<=5;X++) for(Y=1;Y<=5;Y++) for(Z=1;Z<=5;Z++) {
		
		for(i=1;i<=1000;i++) hoge(i,0), hoge(i,1), hoge(i,2);
		
		for(i=1;i<=20;i++) {
			int ng=0;
			for(x=100;x<=1000;x++) {
				FOR(j,3) if(pat[X][Y][Z][j][x]!=pat[X][Y][Z][j][x-i]) ng=1;
			}
			if(ng==0) break;
		}
		rep[X][Y][Z]=i;
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y>>Z;
		
		int nim=0;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]>100) A[i]=(A[i]-100)%rep[X][Y][Z]+100;
			nim^=pat[X][Y][Z][0][A[i]];
		}
		
		int ret=0;
		FOR(i,N) {
			if((hoge(A[i],0)^hoge(A[i]-X,0))==nim) ret++;
			if((hoge(A[i],0)^hoge(A[i]-Y,1))==nim) ret++;
			if((hoge(A[i],0)^hoge(A[i]-Z,2))==nim) ret++;
		}
		
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}