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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		if(S[0]=='D') {
			FORR(c,S) c='R'+'D'-c;
		}
		ll ret=0;
		FOR(i,S.size()) if(S[i]=='D') break;
		if(i==S.size()) {
			ret=N;
		}
		else {
			int sy=0,sx=i;
			y=0;
			ret=x=sx;
			for(j=i;j<S.size();j++) {
				if(S[j]=='D') y++;
				if(S[j]=='R') x++;
			}
			ret+=1LL*(N-sy)*(N-sx);
			ret-=1LL*(y-sy+1)*(x-sx+1)-((int)S.size()+1-i);
			
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