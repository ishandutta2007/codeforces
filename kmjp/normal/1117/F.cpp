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

int N,P;
string S;
int A[17][17];
int nex[18];
int num[18];

vector<int> ngpat[1<<17];
int ok[1<<17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>S;
	FOR(i,P) nex[i]=N;
	FORR(c,S) {
		c-='a';
		num[c]++;
	}
	FOR(y,P) FOR(x,P) cin>>A[y][x];
	for(i=N-1;i>=0;i--) {
		vector<pair<int,int>> V;
		FOR(j,P) if(nex[j]<N) V.push_back({nex[j],j});
		sort(ALL(V));
		int fixed=(1<<P)-1-(1<<S[i]);
		int mat=1<<S[i];
		FORR(v,V) {
			if(v.second!=S[i]) {
				fixed ^= 1<<(v.second);
				mat^= 1<<(v.second);
			}
			if(A[S[i]][v.second]==0) ngpat[fixed].push_back(mat);
			if(v.second==S[i]) break;
			mat^= 1<<(v.second);
		}
		nex[S[i]]=i;
	}
	
	int mask;
	FOR(mask,1<<P) ok[mask]=1;
	FOR(mask,1<<P) {
		sort(ALL(ngpat[mask]));
		ngpat[mask].erase(unique(ALL(ngpat[mask])),ngpat[mask].end());
		for(int submask=mask; submask>=0; submask--) {
			submask&=mask;
			FORR(p,ngpat[mask]) ok[submask|p]=0;
		}
	}
	
	int ma=0;
	FOR(i,P) ma+=num[i];
	for(mask=(1<<P)-2;mask>=0;mask--) if(ok[mask]) {
		ok[mask]=0;
		FOR(i,P) if((mask&(1<<i))==0 && ok[mask|(1<<i)]) ok[mask]=1;
		if(ok[mask]) {
			int sum=0;
			FOR(i,P) if(mask&(1<<i)) sum+=num[i];
			ma=min(ma,sum);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}