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

int T,N,K,A[101010];

int P[101010];
int pre[101010];
int la[101010];
int nex(int a,int p) {
	if(a/p==0) return 1<<30;
	int v=a/p;
	return a/v+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		set<int> S;
		FOR(i,N) {
			cin>>A[i];
			if(P[A[i]]==0) {
				P[A[i]]=1;
				S.insert(A[i]);
				la[A[i]]=A[i];
			}
		}
		int ret=1<<30;
		int ng=0;
		while(S.size()>1) {
			ret=min(ret,*S.rbegin()-*S.begin());
			
			int c=*S.rbegin();
			S.erase(c);
			while(la[c]) {
				int s=la[c];
				la[c]=pre[s];
				
				int v=nex(s,P[s]);
				if(v>K) {
					ng=1;
					la[c]=0;
					break;
				}
				P[s]=v;
				pre[s]=la[s/P[s]];
				la[s/P[s]]=s;
				S.insert(s/P[s]);
			}
			if(ng) break;
		}
		if(ng==0&&S.size()==1) ret=0;
		FORR(s,S) la[s]=0;
		
		cout<<ret<<endl;
		FOR(i,N) P[A[i]]=pre[A[i]]=0;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}