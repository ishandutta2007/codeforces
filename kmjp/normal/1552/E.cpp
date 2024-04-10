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

int N,K;
int C[10101];
int nex[10101][101];
int pre[10101];
int L[101],R[101];

int S[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N*K) {
		cin>>C[i];
		C[i]--;
	}
	FOR(i,N) nex[N*K][i]=N*K;
	for(i=N*K-1;i>=0;i--) {
		FOR(j,N) nex[i][j]=nex[i+1][j];
		nex[i][C[i]]=i;
	}
	MINUS(L);
	
	FOR(i,101) {
		int cur=0;
		while(cur<N*K) {
			int tar=N*K+1,cand,id=-1;
			FOR(j,N) if(L[j]==-1) {
				x=nex[cur][j];
				if(x<N*K) {
					y=nex[x+1][j];
					if(y<tar) cand=x,tar=y, id=j;
				}
			}
			if(tar>=N*K) break;
			L[id]=cand;
			R[id]=tar;
			cur=tar+1;
			S[L[id]]++;
			S[R[id]+1]--;
		}
	}
	
	FOR(i,N*K) {
		if(i) S[i]+=S[i-1];
		assert(S[i]<=(N+(K-2))/(K-1));
	}
	
	FOR(i,N) {
		assert(L[i]>=0);
		cout<<L[i]+1<<" "<<R[i]+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}