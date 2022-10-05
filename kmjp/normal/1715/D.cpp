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


int N,Q;
ll A[101010];
int B[101010];
int L[202020],R[202020],X[202020];
vector<int> ev[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>X[i];
		L[i]--;
		R[i]--;
		if(L[i]>R[i]) swap(L[i],R[i]);
	}
	FOR(i,30) {
		MINUS(B);
		FOR(j,N) ev[j].clear();
		FOR(j,Q) {
			if((X[j]&(1<<i))==0) {
				B[L[j]]=0;
				B[R[j]]=0;
			}
			else {
				ev[L[j]].push_back(R[j]);
				ev[R[j]].push_back(L[j]);
			}
		}
		FOR(j,N) {
			int need=0;
			FORR(e,ev[j]) {
				if(B[e]==0&&B[j]==0) {
					cout<<0<<endl;
					return;
				}
				if(e==j||B[e]==0) B[j]=1;
			}
			if(B[j]==-1) B[j]=0;
		}
		FOR(j,N) A[j]|=B[j]<<i;
	}
	
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}