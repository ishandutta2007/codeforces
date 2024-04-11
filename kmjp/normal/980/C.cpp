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
int P[101010];
int hoge[512];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	MINUS(hoge);
	
	FOR(i,N) {
		cin>>P[i];
		if(hoge[P[i]]==-1) {
			for(x=max(0,P[i]-(K-1));x<=P[i];x++) if(hoge[x]==-1 || hoge[x]>=P[i]-(K-1)) break;
			if(hoge[x]==-1) {
				for(y=x;y<=P[i];y++) hoge[y]=x;
			}
			else {
				for(y=x;y<=P[i];y++) hoge[y]=hoge[x];
			}
		}
		cout<<hoge[P[i]]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}