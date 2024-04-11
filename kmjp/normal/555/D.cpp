#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll X[202020],S[202020];
int A[202020],L[202020],id[202020],rid[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	X[0]=S[0]=-1LL<<31;
	X[N+1]=S[1]=1LL<<31;
	FOR(i,N) cin>>X[i+1], S[i+1]=X[i+1];
	sort(X,X+N+2);
	FOR(i,N) id[i+1]=lower_bound(X,X+(N+2),S[i+1])-X, rid[id[i+1]]=i+1;
	
	FOR(i,M) {
		cin>>x>>y;
		int pre[2]={-1,-1};
		x=id[x];
		int dir=1;
		while(1 && N>1) {
			if(pre[1]==x) y %=(X[pre[0]]-X[x])*2;
			pre[1]=pre[0];
			pre[0]=x;
			
			if(X[x]-X[x-1]>y && X[x+1]-X[x]>y) break;
			FOR(j,2) {
				if(dir==1) {
					auto it=lower_bound(X,X+(N+2),X[x]+y+1);
					
					it--;
					if(*it!=X[x]) {
						y -= *it-X[x];
						x = it-X;
						dir=0;
						break;
					}
				}
				else {
					auto it=lower_bound(X,X+(N+2),X[x]-y);
					
					if(*it!=X[x]) {
						y -= X[x]-*it;
						x = it-X;
						dir=1;
						break;
					}
				}
				dir^=1;
			}
			
		}
		_P("%d\n",rid[x]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}