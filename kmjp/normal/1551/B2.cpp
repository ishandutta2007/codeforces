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

int T,N,K;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		map<int,vector<int>> M;
		FOR(i,N) {
			cin>>x;
			M[x].push_back(i);
			A[i]=0;
		}
		int cur=0;
		FORR2(x,y,M) {
			FOR(i,min((int)y.size(),K)) {
				A[y[i]]=1+cur;
				cur++;
			}
		}
		int ma=cur/K*K;
		FOR(i,N) {
			if(A[i]>ma) A[i]=0;
			if(A[i]) {
				x=(A[i]-1)%K;
				cout<<x+1<<" ";
			}
			else {
				cout<<0<<" ";
			}
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