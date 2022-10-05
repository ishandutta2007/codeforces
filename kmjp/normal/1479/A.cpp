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

int N;
int A[1010101];

int get(int a) {
	if(A[a]==0) {
		cout<<"? "<<a<<endl;
		cin>>A[a];
	}
	return A[a];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A[0]=A[N+1]=1<<20;
	
	if(N<=100) {
		for(i=1;i<=N;i++) {
			get(i);
		}
		for(i=1;i<=N;i++) {
			if(A[i]<A[i-1]&&A[i]<A[i+1]) {
				cout<<"! "<<i<<endl;
				return;
			}
		}
	}
	else {
		int L=0,R=N+1;
		int M=(L+R)/2;
		
		while(R-L>=5) {
			int M=(L+R)/2;
			int L1=(L+M)/2;
			int R1=(R+M)/2;
			int LV=get(L);
			int RV=get(R);
			int MV=get(M);
			int L1V=get(L1);
			int R1V=get(R1);
			
			if(LV>L1V&&L1V<MV) {
				R=M;
			}
			else if(L1V>MV&&MV<R1V) {
				L=L1;
				R=R1;
			}
			else {
				L=M;
			}
			
			
			
		}
		for(i=L;i<=R;i++) get(i);
		for(i=L+1;i<R;i++) {
			if(A[i]<A[i-1]&&A[i]<A[i+1]) {
				cout<<"! "<<i<<endl;
				return;
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