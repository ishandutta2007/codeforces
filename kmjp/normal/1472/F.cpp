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


int T;
int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		map<int,int> B;
		FOR(i,M) {
			cin>>y>>x;
			B[x] |= 1<<(y-1);
		}
		B[N+1]=3;
		int prex=0,cur=0;
		FORR(m,B) {
			if((m.first-prex)%2==0) {
				if(cur==1) cur=2;
				else if(cur==2) cur=1;
			}
			if(cur&m.second) {
				prex=1;
				break;
			}
			
			if(m.second==1) {
				if(cur) cur=0;
				else cur=2;
			}
			else if(m.second==2) {
				if(cur) cur=0;
				else cur=1;
			}
			else {
				cur=0;
			}
			
			prex=m.first;
		}
		if(cur) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}