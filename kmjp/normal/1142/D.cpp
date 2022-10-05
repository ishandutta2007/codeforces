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

int N;
string S;
int num[510500];
int A[510500],B[510500],C[510500],D[510500];
int to[11*11*11][10];
vector<int> avail;
int rev[11*11*11];

ll dp[101010][50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	map<int,int> M;
	for(i=1;i<=9;i++) num[i]=i;
	int nex=10;
	for(i=10;i<=50100;i++) {
		if(num[i/10]==0) continue;
		if(i%10 < num[i/10]%11) num[i]=nex++;
	}
	
	map<int,vector<int>> MM;
	for(i=1;i<100000;i++) if(num[i]) {
		A[i]=num[i]-1;
		x=1;
		while(x*10<=i) x*=10;
		for(j=x;j<x*10;j++) if(num[j]) {
			if(j<i) B[i]++;
			if(j>i) C[i]++;
		}
		A[i]%=11;
		B[i]%=11;
		C[i]%=11;
		D[i]=A[i]*121+B[i]*11+C[i];
		avail.push_back(D[i]);
	}
	MINUS(to);
	for(i=10;i<10000;i++) if(num[i]) to[D[i/10]][i%10]=D[i];
	
	sort(ALL(avail));
	avail.erase(unique(ALL(avail)),avail.end());
	FOR(i,avail.size()) rev[avail[i]]=i;
	
	ll ret=1;
	dp[0][rev[D[S[0]-'0']]]=1;
	for(i=1;i<N;i++) {
		S[i]-='0';
		if(S[i]) {
			dp[i][rev[D[S[i]]]]++;
			ret++;
		}
		FORR(a,avail) if(to[a][S[i]]>=0) {
			dp[i][rev[to[a][S[i]]]]+=dp[i-1][rev[a]];
			ret+=dp[i-1][rev[a]];
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