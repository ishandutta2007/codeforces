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
string S[303];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int sum=0;
		vector<int> C[2][3];
		FOR(y,N) {
			cin>>S[y];
			FOR(x,N) {
				if(S[y][x]=='X') C[0][(y+x)%3].push_back(y*1000+x), sum++;
				if(S[y][x]=='O') C[1][(y+x)%3].push_back(y*1000+x), sum++;
			}
		}
		FOR(i,3) FOR(j,3) if(i!=j&&C[0][i].size()+C[1][j].size()<=sum/3) {
			FORR(v,C[0][i]) S[v/1000][v%1000]='O';
			FORR(v,C[1][j]) S[v/1000][v%1000]='X';
			
			i=j=3;
		}
		FOR(y,N) cout<<S[y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}