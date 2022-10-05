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

int W,N,M;
int A[1<<12];

int num[1<<24];
int table[256][2];

int hoge(int v,char c) {
	if(c=='A') return (v==1)?1:3;
	if(c=='O') return (v==1)?0:1;
	if(c=='X') return (v==1)?2:1;
	if(c=='a') return (v==1)?2:0;
	if(c=='o') return (v==1)?3:2;
	if(c=='x') return (v==1)?1:2;
	return 0;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>N>>M;
	FOR(i,N) cin>>x, A[x]++;
	FOR(i,1<<W) {
		int pos=0;
		FOR(j,W) {
			pos<<=2;
			if(i&(1<<(W-1-j))) pos|=2;
			else pos|=1;
		}
		num[pos]=A[i];
	}
	FOR(i,2*W) {
		FOR(j,1<<(2*W)) if(j&(1<<i)) num[j]+=num[j^(1<<i)];
	}
	FOR(i,256) {
		table[i][0]=hoge(0,i);
		table[i][1]=hoge(1,i);
	}
	
	while(M--) {
		cin>>s;
		ll ret=0;
		FOR(j,1<<W) {
			int pat=0;
			FOR(i,W) {
				pat<<=2;
				if(table[s[i]][(j>>(W-1-i))&1]==0) break;
				pat |= table[s[i]][(j>>(W-1-i))&1];
			}
			ret+=A[j]*num[pat];
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