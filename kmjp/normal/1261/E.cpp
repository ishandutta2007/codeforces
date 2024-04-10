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
int A[1010];
pair<int,int> P[1010];
string S[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) {
		S[i]=string(N,'0');
	}
	int cur=0;
	FOR(i,N) {
		cin>>A[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	reverse(P,P+N);
	
	FOR(i,N) {
		x=P[i].second;
		FOR(y,A[x]) {
			S[i+1+y][x]='1';
		}
		for(j=i+1;j<N;j++) {
			y=P[j].second;
			if(A[y]>1) {
				A[y]--;
				S[i][y]='1';
			}
		}
		
	}
	
	
	
	int num=0;
	FOR(i,N+1) {
		if(count(ALL(S[i]),'1')) num++;
	}
	cout<<num<<endl;
	FOR(i,N+1) {
		if(count(ALL(S[i]),'1')) cout<<S[i]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}