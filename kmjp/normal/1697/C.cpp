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

int Q,N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>S>>T;
		set<int> C[3];
		FOR(i,N) C[S[i]-'a'].insert(i);
		C[0].insert(N);
		C[1].insert(N);
		C[2].insert(N);
		
		FOR(i,N) {
			x=T[i]-'a';
			if(*C[x].begin()==N) break;
			if(T[i]=='a') {
				if(*C[1].begin()<*C[0].begin()) break;
				if(*C[2].begin()<*C[0].begin()) break;
			}
			else if(T[i]=='b') {
				if(*C[2].begin()<*C[1].begin()) break;
			}
			else {
				if(*C[0].begin()<*C[2].begin()) break;
			}
			C[x].erase(C[x].begin());
			
		}
		if(i==N) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}