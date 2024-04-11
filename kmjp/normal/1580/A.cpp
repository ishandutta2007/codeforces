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

int T,H,W;
string A[404];
int R[404][404];
int S[404];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>A[y];
			FOR(x,W) {
				A[y][x]-='0';
				R[y][x]=A[y][x];
				if(x) R[y][x]+=R[y][x-1];
			}
		}
		int ret=1010;
		for(int x1=0;x1<W;x1++) {
			for(int x2=x1+3;x2<W;x2++) {
				int mi=1<<30;
				FOR(y,H) {
					S[y+1]=S[y];
					S[y+1]+=R[y][x2-1]-R[y][x1];
					S[y+1]+=1^A[y][x1];
					S[y+1]+=1^A[y][x2];
					if(y>=4) mi=min(mi,(x2-x1-1)-(R[y-4][x2-1]-R[y-4][x1])-S[y-3]);
					ret=min(ret,mi+(x2-x1-1)-(R[y][x2-1]-R[y][x1])+S[y]);
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