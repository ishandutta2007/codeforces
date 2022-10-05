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

int N;
int A[501][501];
/*
int step1() {
	int vis[3][3]={};
	int x,y,cx,cy;
	FOR(y,3) FOR(x,3) if(A[y][x]==1) cy=y,cx=x;
	
	int tvis=9;
	int vun=0;
	while(tvis) {
		tvis--;
		vis[cy][cx]=1;
		if(tvis==0) return vun;
		int mi=100;
		int tx,ty;
		FOR(y,3) FOR(x,3) if(vis[y][x]==0) {
			if(y==cy||x==cx||x+y==cx+cy||x-y==cx-cy) {
				if(A[y][x]<mi) {
					mi=A[y][x];
					ty=y,tx=x;
				}
			}
		}
		if(mi==100) {
			vun++;
			FOR(y,3) FOR(x,3) if(vis[y][x]==0 && A[y][x]<mi) {
				mi=A[y][x];
				cy=y,cx=x;
			}
		}
		else {
			cy=ty;
			cx=tx;
		}
		
	}
	return vun;
}

int step2() {
	int vis[3][3]={};
	int x,y,cx,cy;
	FOR(y,3) FOR(x,3) if(A[y][x]==1) cy=y,cx=x;
	
	int tvis=9;
	int vun=0;
	while(tvis) {
		tvis--;
		vis[cy][cx]=1;
		if(tvis==0) return vun;
		int mi=100;
		int tx,ty;
		FOR(y,3) FOR(x,3) if(vis[y][x]==0) {
			if(y==cy||x==cx) {
				if(A[y][x]<mi) {
					mi=A[y][x];
					ty=y,tx=x;
				}
			}
		}
		if(mi==100) {
			vun++;
			FOR(y,3) FOR(x,3) if(vis[y][x]==0 && A[y][x]<mi) {
				mi=A[y][x];
				cy=y,cx=x;
			}
		}
		else {
			cy=ty;
			cx=tx;
		}
		
	}
	return vun;
}
*/
string S[3]={
	"124",
	"538",
	"967",
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N<=2) return _P("-1\n");
	/*
	vector<int> V={1,2,3,4,5,6,7,8,9};
	do {
		FOR(i,9) A[i/3][i%3]=V[i];
		if(step1()>step2()) {
			
			cout<<step1()<<" "<<step2()<<endl;
			FOR(y,3) {
				FOR(x,3) cout<<A[y][x];
				cout<<endl;
			}
			cout<<endl;
		}
		
	} while(next_permutation(ALL(V)));
	return;
	*/
	int cur=1;
	for(i=N;i>=4;i--) {
		if(i%2==1) {
			FOR(x,i) A[N-i][x]=cur++;
			FOR(x,i-1) A[N-i+1+x][i-1]=cur++;
		}
		else {
			FOR(x,i-1) A[N-1-x][i-1]=cur++;
			FOR(x,i) A[N-i][i-1-x]=cur++;
		}
	}
	A[N-3][0]=cur++;
	A[N-3][1]=cur++;
	A[N-2][1]=cur++;
	A[N-3][2]=cur++;
	A[N-2][0]=cur++;
	A[N-1][1]=cur++;
	A[N-1][2]=cur++;
	A[N-2][2]=cur++;
	A[N-1][0]=cur++;
	
	FOR(y,N) {
		FOR(x,N) {
			_P("%d",A[y][x]);
			if(x!=N-1) _P(" ");
		}
		_P("\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}