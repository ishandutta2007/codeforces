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


int T,N;
int A[1010][1010];
ll B[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		FOR(y,N) FOR(x,N) scanf("%d",&A[y][x]);
		
		ll ret=0;
		FOR(i,2) {
			FOR(y,N+3) FOR(x,N+3) B[y][x]=0;
			FOR(y,N) {
				FOR(x,N) {
					if((x+y)%2==i) {
						B[y+1][x+1]=A[y][x];
					}
					else {
						if(y==0) B[y+1][x+1]=0;
						else {
							B[y+1][x+1]=B[y][x]^B[y][x+1]^B[y][x+2]^B[y-1][x+1];
							ret^=B[y+1][x+1];
						}
					}
				}
			}
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