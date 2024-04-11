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
int B[101010];

void hoge(vector<int> A,int K) {
	cout<<K<<" ";
	FORR(a,A) cout<<a;
	cout<<" ";
	int i,j;
	vector<int> B=A;
	FOR(i,A.size()) {
		if(A[i]<=K) {
			B[A[i]-1]=A.size()+1;
			FOR(j,i) if(A[j]>K) B[A[i]-1]=A[j];
		}
		else {
			B[A[i]-1]=0;
			FOR(j,i) if(A[j]<=K) B[A[i]-1]=A[j];
		}
	}
	int n0=0,nn=0;
	FORR(b,B) {
		cout<<b;
		if(b==0) n0++;
		if(b==A.size()+1) nn++;
	}
	cout<<"  "<<((n0>0)||(nn>0))<<((n0>0)&&(nn>0))<<endl;
}

vector<int> NE[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	vector<int> V;
	FOR(i,5) V.push_back(i+1);
	do {
		FOR(i,5) hoge(V,i);
	} while(next_permutation(ALL(V)));
	return;
	*/
	
	cin>>T;
	while(T--) {
		cin>>N;
		int KL=0,KR=N;
		x=y=0;
		FOR(i,N+2) NE[i].clear();
		FOR(i,N) {
			cin>>B[i];
			if(B[i]<=i+1) {
				KR=min(KR,i),x++;
			}
			if(B[i]>i+1) {
				KL=max(KL,i+1),y++;
			}
			NE[B[i]].push_back(i+1);
		}
		assert(KL==KR);
		int K=KL;
		queue<int> Q;
		vector<int> V;
		Q.push(0);
		Q.push(N+1);
		cout<<K<<endl;
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			//cout<<cur<<" "<<Q.size()<<endl;
			if(cur>=1&&cur<=N) cout<<cur<<" ";
			FORR(e,NE[cur]) if(NE[e].empty()) Q.push(e);
			FORR(e,NE[cur]) if(NE[e].size()) Q.push(e);
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}