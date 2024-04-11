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
int A[202020];
ll ret;
int nex[32];
map<int,int> mi;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(j,31) nex[j]=N;
	
	for(i=N-1;i>=0;i--) {
		set<int> cand;
		FOR(j,31) if((A[i]&(1<<j))==0) cand.insert(nex[j]);
		int pre=i,now=A[i];
		
		int add=ret;
		FORR(c,cand) {
			if(A[pre]!=now) {
				if(mi.count(now) && mi[now]<c) {
					ret+=mi[now]-pre;
				}
				else {
					ret+=c-pre;
				}
			}
			pre=c,now|=A[c];
		}
		FOR(j,31) if(A[i]&(1<<j)) nex[j]=i;
		mi[A[i]]=i;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}