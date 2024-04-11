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
ll A[101010];
int num[45];
int les[45];
int start[45];
int lessum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		j=0;
		while(1LL<<(j+1)<=A[i]) j++;
		if(A[i]&(A[i]-1)) les[j]++;
		else num[j]++;
	}
	
	vector<int> V;
	int start_sum=0;
	for(i=40;i>=0;i--) {
		int mi=num[i];
		FOR(j,i+1) mi=min(mi,num[j]);
		FOR(j,mi) V.push_back(i);
		start[i]=mi;
		FOR(j,i+1) num[j]-=mi;
		if(j) les[j-1]+=num[j];
	}
	
	vector<int> R;
	for(i=V.size();i>=1;i--) {
		int can=0,lef=0;
		for(j=0;j<=40;j++) {
			lef+=les[j];
			lef-=min(lef,start[j]);
		}
		if(lef==0) R.push_back(i);
		x=V[i-1];
		start[x]--;
		FOR(j,x+1) les[max(0,j-1)]++;
	}
	
	
	sort(ALL(R));
	if(R.empty()) {
		_P("-1\n");
	}
	else {
		FOR(i,R.size()) _P("%d%c",R[i],(i==R.size()-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}