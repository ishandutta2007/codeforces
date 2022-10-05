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
int A[1<<12];
int P[1<<12],RP[1<<12];
int Q[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N=1<<N;
	x=0;
	FOR(i,N) {
		cin>>A[i];
		x^=A[i];
		P[i]=Q[i]=RP[i]=i;
	}
	if(x) return _P("Fou\n");
	FOR(i,N) {
		x=i;
		while((P[x]^Q[x])!=A[x]) {
			y=RP[A[x]^Q[x]];
			RP[P[x]]=y;
			RP[P[y]]=x;
			swap(P[y],P[x]);
			if(y>i) {
				break;
			}
			swap(Q[y],Q[i+1]);
			x=y;
		}
	}
	cout<<"Shi"<<endl;
	FOR(i,N) cout<<P[i]<<" ";
	cout<<endl;
	FOR(i,N) cout<<Q[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}