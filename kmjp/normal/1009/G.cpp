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
int N,M;
int C[6];
int mask[101010];
int pat[101010][64];
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) C[c-'a']++;
	FOR(i,N) mask[i]=(1<<6)-1;
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>s;
		x--;
		mask[x]=0;
		FORR(c,s) mask[x] |= 1<<(c-'a');
	}
	for(i=N-1;i>=0;i--) {
		FOR(x,64) pat[i][x]=pat[i+1][x];
		pat[i][mask[i]]++;
	}
	FOR(i,N) {
		FOR(x,6) {
			FOR(y,64) if(y&(1<<x)) pat[i][y] += pat[i][y^(1<<x)];
		}
	}
	
	FOR(i,N) {
		FOR(j,6) if(C[j] && (mask[i]&(1<<j))) {
			C[j]--;
			int m;
			FOR(m,64) {
				int tot=0;
				FOR(x,6) if(m&(1<<x)) tot+=C[x];
				if(tot<pat[i+1][m]) break;
			}
			
			if(m==64) {
				T+='a'+j;
				break;
			}
			
			
			C[j]++;
		}
		if(j==6) return _P("Impossible");
	}
	cout<<T<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}