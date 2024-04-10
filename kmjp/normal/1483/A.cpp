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
vector<int> V[101010];
int C[202020];
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) C[i+1]=0;
		FOR(i,M) {
			cin>>x;
			V[i].resize(x);
			FOR(j,x) {
				cin>>V[i][j];
				C[V[i][j]]++;
			}
		}
		int ma=0;
		for(i=1;i<=N;i++) if(C[i]>C[ma]) ma=i;
		int del=max(0,C[ma]-(M+1)/2);
		FOR(i,M) {
			if(count(ALL(V[i]),ma)) {
				if(del==0) {
					R[i]=ma;
				}
				else if(V[i].size()>1) {
					del--;
					if(V[i][0]==ma) R[i]=V[i][1];
					else R[i]=V[i][0];
				}
				else {
					R[i]=ma;
				}
			}
			else {
				R[i]=V[i][0];
			}
		}
		if(del==0) {
			cout<<"YES"<<endl;
			FOR(i,M) cout<<R[i]<<" ";
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