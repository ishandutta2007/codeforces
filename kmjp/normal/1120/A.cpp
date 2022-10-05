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

int M,K,N,S;
int A[505050];
map<int,int> need,need2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d%d",&M,&K,&N,&S);
	FOR(i,M) scanf("%d",&A[i]);
	FOR(i,S) {
		scanf("%d",&x);
		need[x]++;
	}
	need2=need;
	
	
	int over=need.size();
	int L,R=0;
	FOR(L,M) {
		while(R<M && (over>0 || R-L<K)) {
			need[A[R]]--;
			if(need[A[R]]==0) over--;
			R++;
		}
		if(over==0 && L/K+(M-R)/K>=N-1) {
			vector<int> ret;
			int add=min(N-1,L/K);
			N-=add;
			FOR(i,L-add*K) ret.push_back(i);
			add=min(N-1,(M-R)/K);
			N-=add;
			FOR(i,M-R-add*K) ret.push_back(M-1-i);
			
			vector<int> C;
			for(i=L;i<R;i++) {
				if(need2[A[i]]) {
					need2[A[i]]--;
				}
				else {
					C.push_back(i);
				}
			}
			C.resize(R-L-K);
			FORR(c,C) ret.push_back(c);
			
			sort(ALL(ret));
			cout<<ret.size()<<endl;
			FORR(r,ret) cout<<(r+1)<<" ";
			return;
			
		}
		
		if(need[A[L]]==0) over++;
		need[A[L]]++;
	}
	
	cout<<-1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}