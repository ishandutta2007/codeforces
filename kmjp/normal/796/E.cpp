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

int N,P,K;
int A[2][1110];
int num[2][1110][1110];
int only[2][1110][1110];
const int sz=500000;
int from[sz],to[sz];

int id(int p,int x,int y) {return p*(K+2)*(K+2)+x*(K+2)+y;}
void update(int p,int x,int y,int v) {
	int& r=to[id(p,x,y)];
	r = max(r,v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>K;
	cin>>x;
	FOR(i,x) cin>>r, A[0][r-1]=1;
	cin>>x;
	FOR(i,x) cin>>r, A[1][r-1]=1;
	
	if(P/2*K>=N) {
		int cnt=0;
		FOR(i,N) cnt += A[0][i] | A[1][i];
		return _P("%d\n",cnt);
	}
	
	FOR(x,N) {
		for(y=x;y<N+K;y++) {
			num[0][x][y] = (y?num[0][x][y-1]:0) + A[0][y];
			num[1][x][y] = (y?num[1][x][y-1]:0) + A[1][y];
			only[0][x][y] = (y?only[0][x][y-1]:0) + (A[0][y] & !A[1][y]);
			only[1][x][y] = (y?only[1][x][y-1]:0) + (A[1][y] & !A[0][y]);
		}
	}
	
	for(i=N-1;i>=0;i--) {
		ZERO(to);
		for(j=0;j<=P;j++) {
			FOR(x,K+1) FOR(y,K+1) {
				int r = from[id(j,x,y)];
				update(j,min(x+1,K),min(y+1,K),r);
				if(j) {
					if(x<=y) {
						update(j-1,1,min(y+1,K),r+num[0][i][i+x-1]);
						update(j-1,min(x+1,K),1,r+num[1][i][i+x-1]+only[1][i+x][i+y-1]);
					}
					else {
						update(j-1,1,min(y+1,K),r+num[0][i][i+y-1]+only[0][i+y][i+x-1]);
						update(j-1,min(x+1,K),1,r+num[1][i][i+y-1]);
					}
					
				}
				if(j>=2) {
					if(x<=y) update(j-2,1,1,r+num[0][i][i+x-1]+only[1][i][i+y-1]);
					else update(j-2,1,1,r+only[0][i][i+x-1]+num[1][i][i+y-1]);
				}
			}
		}
		
		swap(from,to);
	}

	int ma=0;
	FOR(i,sz) ma=max(ma,from[i]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}