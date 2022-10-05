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

int T,N;
int A[202020];
vector<pair<int,int>> R;

void go(int x,int y) {
	R.push_back({x,y});
	A[x]=(A[x]+A[y]-1)/A[y];
}

int cnt(int x,int y) {
	int num=0;
	while(x>1||y>2) {
		if(x==1) return 1010;
		num++;
		y=(y+x-1)/x;
		if(x>y) swap(x,y);
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		R.clear();
		for(i=1;i<=N;i++) A[i]=i;
		
		int mi=100,tar=0;
		for(i=1;i<N;i++) {
			x=cnt(i,N);
			if(x<mi) mi=x, tar=i;
		}
		
		for(i=1;i<N;i++) if(i!=tar) go(i,N);
		while(A[tar]+A[N]>3) {
			if(A[tar]>A[N]) go(tar,N);
			else go(N,tar);
		}
		int C[3]={};
		for(i=1;i<=N;i++) {
			assert(A[i]==1||A[i]==2);
			C[A[i]]++;
		}
		assert(C[2]==1);
		assert(R.size()<=N+5);
		cout<<R.size()<<endl;
		FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}