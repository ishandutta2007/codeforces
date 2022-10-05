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
int N;
int A[303030];
int Q;
int G[1010101];
ll W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) {
		G[i]=i;
	}
	for(i=2;i<=1000;i++) {
		x=i*i;
		for(y=x;y<=1000000;y+=x) while(G[y]%x==0) G[y]/=x;
	}
	
	cin>>T;
	while(T--) {
		map<int,int> M[3];
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			M[0][G[A[i]]]++;
		}
		
		FOR(i,2) {
			FORR(m,M[i]) {
				if(m.second%2==0) {
					M[i+1][1]+=m.second;
				}
				else {
					M[i+1][m.first]+=m.second;
				}
			}
		}
		int ma[3]={};
		FOR(i,3) {
			FORR(m,M[i]) ma[i]=max(ma[i],m.second);
		}
		
		cin>>Q;
		while(Q--) {
			cin>>W;
			if(W>=2) cout<<ma[2]<<endl;
			else cout<<ma[W]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}