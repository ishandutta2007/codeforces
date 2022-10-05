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
string S[505050];
string T[505050];
string R[505050];

char dec(char c) {
	if(c=='A') return 0;
	if(c=='T') return 1;
	if(c=='C') return 2;
	if(c=='G') return 3;
}

char enc(char c) {
	if(c==0) return 'A';
	if(c==1) return 'T';
	if(c==2) return 'C';
	if(c==3) return 'G';
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) c=dec(c);
	}
	
	int mi=1<<30;
	for(int mask=0;mask<1<<4;mask++) if(__builtin_popcount(mask)==2) {
		vector<char> C[2];
		FOR(i,4) C[(mask>>i)&1].push_back(i);
		int tot=0;
		FOR(y,H) {
			int cnt[2]={};
			FOR(i,2) {
				FOR(x,W) cnt[i]+=S[y][x]!=C[y%2][(x%2)^i];
			}
			j=(cnt[1]<cnt[0]);
			tot+=cnt[j];
			T[y].clear();
			FOR(x,W) T[y].push_back(C[y%2][(x%2)^j]);
		}
		if(tot<mi) {
			mi=tot;
			FOR(y,H) R[y]=T[y];
		}
		
		tot=0;
		FOR(y,H) T[y].clear();
		FOR(x,W) {
			int cnt[2]={};
			FOR(i,2) {
				FOR(y,H) cnt[i]+=S[y][x]!=C[x%2][(y%2)^i];
			}
			j=(cnt[1]<cnt[0]);
			tot+=cnt[j];
			FOR(y,H) T[y].push_back(C[x%2][(y%2)^j]);
		}
		if(tot<mi) {
			mi=tot;
			FOR(y,H) R[y]=T[y];
		}
		
	}
	
	FOR(y,H) {
		FORR(c,R[y]) c=enc(c);
		cout<<R[y]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}