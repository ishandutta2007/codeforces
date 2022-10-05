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
int N,K;
int H[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		for(i=1;i<=N;i++) H[i]=1010;
		FOR(i,K) {
			cin>>x;
			H[x]=1;
		}
		FOR(i,202) {
			for(j=1;j<=N;j++) {
				if(j>1) H[j]=min(H[j],H[j-1]+1);
				if(j<N) H[j]=min(H[j],H[j+1]+1);
			}
		}
		
		int ma=0;
		for(i=1;i<=N;i++) ma=max(ma,H[i]);
		cout<<ma<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}