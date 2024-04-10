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

int T;
int N;
string S[2020];
string SS[2020];

void rotate(int N) {
	int x,y;
	FOR(y,N) SS[y]=S[y];
	FOR(y,N) FOR(x,N) S[y][x]=SS[N-1-x][y];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(y,N) cin>>S[y];
		FOR(i,10) {
			int ma=0;
			
			FOR(j,4) {
				int lef=2020;
				FOR(x,N) {
					int mi=2020;
					FOR(y,N) if(S[y][x]=='0'+i) {
						if(mi==2020) mi=y;
						if(lef==2020) lef=x;
						// changel left
						ma=max(ma,x*(y-mi));
						// change up
						ma=max(ma,(x-lef)*(y-0));
						// change down
						ma=max(ma,(x-lef)*(N-1-mi));
					}
				}
				rotate(N);
			}
			cout<<ma<<" ";
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