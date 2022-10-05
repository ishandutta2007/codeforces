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
int A[101][101];
int B[101][101];

int ask(int y1,int x1,int y2,int x2) {
	y1++,x1++,y2++,x2++;
	int r;
	cout<<"? "<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<endl;
	cin>>r;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,N) A[y][x]=2;
	A[0][0]=1;
	A[N-1][N-1]=0;
	for(i=0;i<=2*N;i+=2) {
		FOR(y,N) FOR(x,N) if(x+y==i && A[y][x]==2) {
			int y2,x2;
			if(y>=2) y2=y-2,x2=x;
			else if(x&&y) y2=y-1,x2=x-1;
			else if(x>=2) y2=y,x2=x-2;
			int v=ask(y2,x2,y,x);
			if(v) A[y][x]=A[y2][x2];
			else A[y][x]=1^A[y2][x2];
		}
	}
	A[0][1]=0;
	for(i=1;i<=2*N;i+=2) {
		FOR(y,N) FOR(x,N) if(x>0 && x+y==i && A[y][x]==2) {
			int y2,x2;
			if(y>=2) y2=y-2,x2=x;
			else if(x>=2&&y) y2=y-1,x2=x-1;
			else if(x>=2) y2=y,x2=x-2;
			int v=ask(y2,x2,y,x);
			if(v) A[y][x]=A[y2][x2];
			else A[y][x]=1^A[y2][x2];
		}
	}
	for(y=1;y<N;y+=2) {
		A[y][0]=1^ask(y,0,y,2)^A[y][2];
	}
	
	int flip=0;
	FOR(y,N) FOR(x,N) {
		if(y+3<=N && x+2<=N && (A[y+1][x]!=A[y][x+1] || A[y+2][x]!=A[y+1][x+1])) {
			int v=ask(y,x,y+2,x+1);
			flip=1^v^(A[y][x]^A[y+2][x+1]);
			goto out;
		}
		if(y+2<=N && x+3<=N && (A[y+1][x]!=A[y][x+1] || A[y+1][x+1]!=A[y][x+2])) {
			int v=ask(y,x,y+1,x+2);
			flip=1^v^(A[y][x]^A[y+1][x+2]);
			goto out;
		}
		if(y+3<=N && x+2<=N && (A[y][x]==A[y+1][x+1]&&A[y][x]==A[y+2][x]&&A[y][x+1]==A[y+1][x]&&A[y][x+1]==A[y+2][x+1])) {
			int v=ask(y,x,y+2,x+1);
			flip=1^v^(A[y][x]^A[y+2][x+1]);
			goto out;
		}
		if(y+2<=N && x+3<=N && (A[y][x]==A[y+1][x+1]&&A[y][x]==A[y][x+2]&&A[y+1][x]==A[y][x+1]&&A[y+1][x]==A[y+1][x+2])) {
			int v=ask(y,x,y+1,x+2);
			flip=1^v^(A[y][x]^A[y+1][x+2]);
			goto out;
		}
		if(y+4<=N && (A[y][x]==A[y+2][x]&&A[y+1][x]==A[y+3][x])) {
			int v=ask(y,x,y+3,x);
			flip=1^v^(A[y][x]^A[y+3][x]);
			goto out;
		}
		if(x+4<=N && (A[y][x]==A[y][x+2]&&A[y][x+1]==A[y][x+3])) {
			int v=ask(y,x,y,x+3);
			flip=1^v^(A[y][x]^A[y][x+3]);
			goto out;
		}
		if(y+4<=N && (A[y][x]==A[y+3][x]&&A[y+1][x]==A[y+2][x])) {
			int v=ask(y,x,y+3,x);
			flip=1^v^(A[y][x]^A[y+3][x]);
			goto out;
		}
		if(x+4<=N && (A[y][x]==A[y][x+3]&&A[y][x+1]==A[y][x+2])) {
			int v=ask(y,x,y,x+3);
			flip=1^v^(A[y][x]^A[y][x+3]);
			goto out;
		}
	}
	assert(0);
	out:
	cout<<"!"<<endl;
	FOR(y,N) {
		FOR(x,N) {
			if((y+x)%2) A[y][x]^=flip;
			cout<<A[y][x];
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}