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

int H,W,Q;
string S[1010];
int C[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='*') C[x]++;
	}
	
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		if(S[y][x]=='.') {
			C[x]++;
			S[y][x]='*';
		}
		else {
			C[x]--;
			S[y][x]='.';
		}
		int sum=0;
		FOR(x,W) sum+=C[x];
		int ret=0;
		FOR(x,W) {
			int v=min(H,sum);
			if(v==H) {
				ret+=v-C[x];
			}
			else if(v) {
				FOR(y,v) if(S[y][x]=='.') ret++;
			}
			sum-=v;
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