#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N,Q;
string S;
char buf[303030];
int A[303030];

set<pair<int,int>> LP,LM;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		
		scanf("%d%d",&N,&Q);
		scanf("%s",buf);
		S=buf;
		LP.clear();
		LM.clear();
		FOR(i,N) {
			A[i+1]=A[i];
			if(i%2==1) S[i]='+'+'-'-S[i];
			if(S[i]=='+') {
				A[i+1]++;
				LP.insert({A[i+1],i+1});
			}
			else {
				A[i+1]--;
				LM.insert({A[i+1],i+1});
			}
		}
		LP.insert({N+1,N+1});
		LM.insert({N+1,N+1});
		
		while(Q--) {
			int L,R;
			scanf("%d%d",&L,&R);
			x=A[R]-A[L-1];
			if(x==0) {
				_P("0\n");
			}
			else if(R%2==L%2) {
				k=A[L-1];
				y=-1;
				auto it=LP.lower_bound({k+(x+1)/2,L});
				if(it->first==k+(x+1)/2&&it->second<=R) y=it->second;
				it=LM.lower_bound({k+(x-1)/2,L});
				if(it->first==k+(x-1)/2&&it->second<=R) y=it->second;
				
				_P("1\n%d\n",y);
				
			}
			else {
				R--;
				x=A[R]-A[L-1];
				k=A[L-1];
				y=-1;
				auto it=LP.lower_bound({k+(x+1)/2,L});
				if(it->first==k+(x+1)/2&&it->second<=R) y=it->second;
				it=LM.lower_bound({k+(x-1)/2,L});
				if(it->first==k+(x-1)/2&&it->second<=R) y=it->second;
				
				
				_P("2\n%d %d\n",y,R+1);
			}
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}