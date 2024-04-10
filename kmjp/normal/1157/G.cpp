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

int H,W;
int A[202][202];
int R[202],C[202];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	if(H==1) {
		cout<<"YES"<<endl;
		cout<<0<<endl;
		FOR(x,W) cout<<A[0][x];
		cout<<endl;
		return;
	}
	
	// first;
	FOR(x,W) C[x]=A[0][x];
	int ng=303;
	FOR(y,H) {
		int dif=0;
		FOR(x,W-1) if((A[y][x]^C[x])!=(A[y][x+1]^C[x+1])) dif++;
		if(dif>1) break;
		if(dif==1) {
			if(ng!=303) break;
			ng=y;
		}
	}
	if(y==H) {
		cout<<"YES"<<endl;
		FOR(y,H) {
			x=A[y][0]^C[0];
			if(y<=ng) cout<<x;
			else cout<<(1-x);
		}
		cout<<endl;
		FOR(x,W) cout<<C[x];
		cout<<endl;
		return;
	}
	
	FOR(x,W) C[x]=A[1][x];
	ng=303;
	FOR(y,H) {
		int dif=0;
		FOR(x,W-1) if((A[y][x]^C[x])!=(A[y][x+1]^C[x+1])) dif++;
		if(dif>1) break;
		if(dif==1) {
			if(ng!=303) break;
			ng=y;
		}
	}
	
	if(y==H) {
		cout<<"YES"<<endl;
		FOR(y,H) {
			x=A[y][0]^C[0];
			if(y<=ng) cout<<x;
			else cout<<(1-x);
		}
		cout<<endl;
		FOR(x,W) cout<<C[x];
		cout<<endl;
		return;
	}
	cout<<"NO"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}