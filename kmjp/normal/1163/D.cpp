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


string C,S,T;
int N,A,B;
int nex[51][26][2];

int from[50500];
int to[50500];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>C>>S>>T;
	N=C.size();
	A=S.size();
	B=T.size();
	FOR(i,A) {
		FOR(x,26) {
			string U=S.substr(0,i)+(char)('a'+x);
			if(U==S) {
				nex[i][x][0]=A;
				for(y=1;y<A;y++) if(U.substr(i+1-y)==S.substr(0,y)) nex[i][x][0]=max(nex[i][x][0],A+y);
			}
			else {
				for(y=1;y<=i+1;y++) if(U.substr(i+1-y)==S.substr(0,y)) nex[i][x][0]=max(nex[i][x][0],y);
			}
		}
	}
	FOR(i,B) {
		FOR(x,26) {
			string U=T.substr(0,i)+(char)('a'+x);
			if(U==T) {
				nex[i][x][1]=B;
				for(y=1;y<B;y++) if(U.substr(i+1-y)==T.substr(0,y)) nex[i][x][1]=max(nex[i][x][1],B+y);
			}
			else {
				for(y=1;y<=i+1;y++) if(U.substr(i+1-y)==T.substr(0,y)) nex[i][x][1]=max(nex[i][x][1],y);
			}
		}
	}
	
	from[0]=0;
	for(i=1;i<=50*N;i++) from[i]=1<<30;
	FOR(i,N) {
		FOR(j,50*N+1) to[j]=1<<30;
		FOR(j,50*N+1) if(from[j]<1<<29) {
			FOR(x,26) if(C[i]=='*' || C[i]=='a'+x) {
				to[nex[j%A][x][0]+j/A*A]=min(to[nex[j%A][x][0]+j/A*A],nex[from[j]%B][x][1]+from[j]/B*B);
			}
		}
		
		swap(from,to);
	}
	
	int ma=-1<<29;
	FOR(i,50*N+1) ma=max(ma,i/A-from[i]/B);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}