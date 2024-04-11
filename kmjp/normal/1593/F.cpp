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
int N,A,B;
string S;

vector<int> from[41][81][40][40];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>S;
		FOR(i,N+1) FOR(j,81) FOR(x,40) FOR(y,40) from[i][j][x][y].clear();
		from[0][40][0][0]={0,0,0,0};
		FOR(i,N) {
			int c=S[i]-'0';
			FOR(j,81) FOR(x,A) FOR(y,B) if(from[i][j][x][y].size()) {
				from[i+1][j+1][(x*10+c)%A][y]={i,j,x,y};
				from[i+1][j-1][x][(y*10+c)%B]={i,j,x,y};
			}
		}
		
		int besta=88;
		FOR(j,81) if(from[N][j][0][0].size()) {
			if(j==40+N||j==40-N) continue;
			if(abs(j-40)<abs(besta-40)) besta=j;
		}
		
		if(besta==88) {
			cout<<-1<<endl;
		}
		else {
			i=N,j=besta,x=y=0;
			string R;
			while(i) {
				auto a=from[i][j][x][y];
				if(a[1]>j) R+="B";
				else R+="R";
				i=a[0];j=a[1];x=a[2];y=a[3];
			}
			reverse(ALL(R));
			cout<<R<<endl;
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}