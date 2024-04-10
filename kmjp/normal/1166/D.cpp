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

int Q;
ll A,B,M;
ll cand[55];
ll R[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B>>M;
		ZERO(cand);
		if(A==B) {
			cout<<"1 "<<A<<endl;
			continue;
		}
		for(int l=2;l<=50;l++) {
			ll mi=A<<(l-2);
			ll ma=A<<(l-2);
			for(x=2;x<=l;x++) {
				cand[x]=1;
				mi+=1LL<<max(0,l-x-1);
				ma+=M<<max(0,l-x-1);
			}
			if(mi>B) {
				cout<<-1<<endl;
				break;
			}
			if(ma<B) continue;
			ll diff=B-mi;
			for(x=2;x<=l;x++) {
				ll hoge=1LL<<max(0,l-x-1);
				ll ok=min(M-1,diff/hoge);
				cand[x]+=ok;
				diff-=ok*hoge;
			}
			
			ll S=A;
			R[1]=A;
			for(x=2;x<=l;x++) {
				R[x]=S+cand[x];
				S+=R[x];
			}
			cout<<l;
			for(x=1;x<=l;x++) cout<<" "<<R[x];
			cout<<endl;
			
			break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}