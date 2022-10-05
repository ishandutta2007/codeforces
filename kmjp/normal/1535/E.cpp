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


int Q;
int N;
ll A[303030],C[303030];
int P[303030][20];
int V;
ll W;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>A[0]>>C[0];
	for(i=1;i<=Q;i++) {
		cin>>x;
		if(x==1) {
			cin>>P[i][0]>>A[i]>>C[i];
			FOR(j,19) P[i][j+1]=P[P[i][j]][j];
			
		}
		else {
			cin>>V>>W;
			ll sum=0,sc=0;
			
			while(W&&A[V]) {
				int tar=V;
				for(j=19;j>=0;j--) if(A[P[tar][j]]) tar=P[tar][j];
				ll a=min(W,A[tar]);
				sum+=a;
				sc+=a*C[tar];
				A[tar]-=a;
				W-=a;
			}
			cout<<sum<<" "<<sc<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}