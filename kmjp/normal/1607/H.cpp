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

int T,N,A[202020],B[202020],M[202020];
int TL[202020],TR[202020];
set<pair<int,int>> L[2020200],R[2020200];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		set<int> cand;
		cin>>N;
		FOR(i,N) {
			cin>>A[i]>>B[i]>>M[i];
			x=A[i]+B[i]-M[i];
			cand.insert(A[i]+B[i]-M[i]);
			L[x].insert({max(0,A[i]-M[i]),i});
			R[x].insert({A[i]-max(0,M[i]-B[i]),i});
		}
		int num=0;
		FORR(c,cand) {
			while(R[c].size()) {
				num++;
				x=R[c].begin()->first;
				y=R[c].begin()->second;
				R[c].erase(R[c].begin());
				while(L[c].size()&&L[c].begin()->first<=x) {
					k=L[c].begin()->second;
					L[c].erase(L[c].begin());
					R[c].erase(make_pair(A[k]-max(0,M[k]-B[k]),k));
					TL[k]=A[k]-x;
					TR[k]=M[k]-(A[k]-x);
				}
			}
			
			L[c].clear();
			R[c].clear();
		}
		cout<<num<<endl;
		FOR(i,N) cout<<TL[i]<<" "<<TR[i]<<endl;
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}