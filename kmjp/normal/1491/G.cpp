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
int C[202020];
int vis[202020];
vector<vector<int>> P;
vector<pair<int,int>> R;

void add(int& a,int& b) {
	R.push_back({a,b});
	swap(C[a],C[b]);
	C[a]=-C[a];
	C[b]=-C[b];
}

void go_single(vector<int> P) {
	int N=P.size();
	
	
	if(N==2) {
		int tar=1;
		while(tar==P[0]||tar==P[1]) tar++;
		R.push_back({P[0],tar});
		R.push_back({P[1],tar});
		R.push_back({P[0],tar});
		
	}
	else {
		add(P[N-2],P[N-1]);
		add(P[N-3],P[N-1]);
		for(int i=0;i<N-2;i++) add(P[i],P[N-2]);
		add(P[N-2],P[N-1]);
		
	}
}

void go_twin(vector<int> A,vector<int> B) {
	int N=A.size();
	int M=B.size();
	deque<int> P,Q;
	FORR(a,A) P.push_back(a);
	FORR(a,B) Q.push_back(a);
	
	
	add(P.back(),Q.back());
	while(Q.size()>1) {
		add(P.back(),Q[0]);
		Q.pop_front();
	}
	while(P.size()>1) {
		add(Q.back(),P[0]);
		P.pop_front();
	}
	add(P[0],Q[0]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i+1];
	
	for(i=1;i<=N;i++) if(vis[i]==0) {
		vector<int> A;
		x=i;
		while(vis[x]==0) {
			A.push_back(x);
			vis[x]=1;
			x=C[x];
		}
		if(A.size()>1) P.push_back(A);
	}
	
	while(P.size()>=2) {
		go_twin(P[P.size()-1],P[P.size()-2]);
		P.pop_back();
		P.pop_back();
	}
	
	if(P.size()) go_single(P[0]);
	
	//FOR(i,N) cout<<C[i+1];
	//cout<<endl;
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}