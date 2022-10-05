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
int B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> X;
		for(i=1;i<=2*N;i++) X.insert(i);
		FOR(i,N) {
			cin>>B[i];
			X.erase(B[i]);
		}
		int mi=0;
		set<int> Y=X;
		FOR(i,N) {
			auto it=X.lower_bound(B[i]);
			if(it!=X.end()) {
				mi++;
				X.erase(it);
			}
		}
		int ma=N;
		for(i=N-1;i>=0;i--) {
			auto it=Y.lower_bound(B[i]);
			if(it!=Y.begin()) {
				it--;
				ma--;
				Y.erase(it);
			}
		}
		
		cout<<mi-ma+1<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}