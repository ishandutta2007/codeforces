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

ll A,B,H,W;
int N;
ll C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>H>>W>>N;
	FOR(i,N) cin>>C[i];
	sort(C,C+N);
	reverse(C,C+N);
	N=min(35,N);
	
	if(max(H,W)>=max(A,B) && min(H,W)>=min(A,B)) return _P("0\n");
	
	set<ll> S;
	S.insert(1);
	ll tot=1;
	FOR(i,N) {
		set<ll> S2=S;
		if(tot*C[i]/C[i]!=tot) break;
		tot *= C[i];
		
		FORR(r,S2) S.insert(min(r*C[i],100000LL));
		int ok=0;
		FORR(r,S) {
			if(r*H>=A && (tot/r)*W>=B) ok=1;
			if(r*H>=B && (tot/r)*W>=A) ok=1;
		}
		if(ok) break;
	}
	if(i==N) cout<<-1<<endl;
	else cout<<i+1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}