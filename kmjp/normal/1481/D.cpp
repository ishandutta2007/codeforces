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

int T,N,M;
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(y,N) cin>>S[y];
		
		int a=-1,b;
		FOR(y,N) FOR(x,y) if(S[y][x]==S[x][y]) a=x,b=y;
		
		if(a>=0) {
			cout<<"YES"<<endl;
			FOR(i,M+1) {
				if(i%2==0) cout<<a+1<<" ";
				else cout<<b+1<<" ";
			}
			cout<<endl;
		}
		else if(M%2==1) {
			cout<<"YES"<<endl;
			FOR(i,M+1) cout<<i%2+1<<" ";
			cout<<endl;
		}
		else if(N>=3) {
			int C[3]={};
			FOR(y,3) {
				FOR(x,3) if(S[y][x]=='a') C[y]++;
			}
			cout<<"YES"<<endl;
			if(C[0]==1&&C[1]==1&&C[2]==1) {
				FOR(i,M+1) cout<<1+(i%3)<<" ";
			}
			else {
				int D[3]={};
				FOR(i,3) D[C[i]]=i+1;
				deque<int> Q;
				Q.push_back(D[0]);
				Q.push_back(D[1]);
				Q.push_back(D[2]);
				while(Q.size()<=M) {
					if(Q[0]==D[0]) {
						Q.push_front(D[2]);
						Q.push_back(D[0]);
					}
					else {
						Q.push_front(D[0]);
						Q.push_back(D[2]);
					}
				}
				FORR(q,Q) cout<<q<<" ";
			}
			cout<<endl;
			
			
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