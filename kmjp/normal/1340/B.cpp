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


int N,K;
int ok[2020][10];

int mask[10];
string T[10]={
	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011",
};

bitset<2048> BS[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ok);
	
	FOR(i,10) {
		FOR(j,7) if(T[i][j]=='1') mask[i]|=1<<j;
	}
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>s;
		x=0;
		FOR(j,7) if(s[j]=='1') x|=1<<j;
		FOR(j,10) if((mask[j]&x)==x) ok[i][j]=__builtin_popcount(mask[j]^x);
	}
	BS[N][0]=1;
	for(i=N-1;i>=0;i--) {
		FOR(j,2001) if(BS[i+1][j]) {
			FOR(k,10) if(ok[i][k]>=0) BS[i][j+ok[i][k]]=1;
		}
	}
	
	if(BS[0][K]==0) return _P("-1\n");
	string ret;
	FOR(i,N) {
		for(j=9;j>=0;j--) if(ok[i][j]>=0 && ok[i][j]<=K && BS[i+1][K-ok[i][j]]==1) {
			ret+='0'+j;
			K-=ok[i][j];
			break;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}