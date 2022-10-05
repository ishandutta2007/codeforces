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

int T;
int H,W;
string S[2020];
int L[27],R[27],U[27],D[27];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>H>>W;
		FOR(i,27) {
			L[i]=W;
			R[i]=-1;
			U[i]=H;
			D[i]=-1;
		}
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) {
				if(S[y][x]=='.') S[y][x]='a'-1;
				if(S[y][x]>='a') {
					i=S[y][x]-'a';
					L[i]=min(L[i],x);
					R[i]=max(R[i],x);
					U[i]=min(U[i],y);
					D[i]=max(D[i],y);
				}
			}
		}
		int ok=1;
		for(i=25;i>=0;i--) {
			if(R[i]==-1) {
				L[i]=L[i+1];
				R[i]=R[i+1];
				U[i]=U[i+1];
				D[i]=D[i+1];
			}
			if(R[i]!=-1) {
				if(L[i]!=R[i]&&U[i]!=D[i]) ok=0;
			}
		}
		FOR(y,H) {
			FOR(x,W) {
				int id=-1;
				FOR(i,26) {
					if(y>=U[i]&&y<=D[i]&&x>=L[i]&&x<=R[i]) id=i;
				}
				if(S[y][x]!=id+'a') ok=0;
			}
		}
		
		if(ok==0) {
			_P("NO\n");
		}
		else {
			FOR(x,26) if(R[x]==-1) break;
			_P("YES\n%d\n",x);
			FOR(y,x) _P("%d %d %d %d\n",U[y]+1,L[y]+1,D[y]+1,R[y]+1);
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}