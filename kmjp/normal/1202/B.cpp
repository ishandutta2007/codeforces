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


string S;
int N;

int cnt[10][10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(x,10) FOR(y,10) {
		FOR(i,10) cnt[x][y][i]=1010;
		FOR(i,10) FOR(j,10) if(i+j) {
			k=(x*i+y*j)%10;
			cnt[x][y][k]=min(cnt[x][y][k],i+j);
		}
	}
	
	FOR(i,10) {
		FOR(j,10) {
			ll ret=0;
			FOR(x,N-1) {
				y=S[x+1]-S[x];
				if(y<0) y+=10;
				if(cnt[i][j][y]==1010) break;
				ret+=cnt[i][j][y]-1;
			}
			if(x<N-1) {
				cout<<-1<<" ";
			}
			else {
				cout<<ret<<" ";
			}
			
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